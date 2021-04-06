const express = require('express');
const router = express.Router();
const example_sql = require('../models/example_model');

router.get('/allpersons',
    function(request,response){
        example_sql.getAllPersons(function(err, dbResult){
            if(err){
                response.json(err.errno);
            }
            else{
                console.log(dbResult);
                response.json(dbResult);
            }
        }
        )
    }
);

router.get('/oneperson/:id',
    function(request, response){
        example_sql.getOnePerson(request.params.id,function(err,dbResult){
            if(err){
                response.json(err.errno);
            }
            else{
                console.log(dbResult);
                response.json(dbResult[0]);
            }
        })
    }
);

router.get('/fullname/:id',
    function(request, response){
        example_sql.getFullName(request.params.id,
            function(err,dbResult){
                if(err){
                    response.json(err.errno);
                }
                else{
                    response.json(dbResult[0]);
                }
            })
        }
);

module.exports = router;