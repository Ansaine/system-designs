import express from 'express'

// import everthing from controller
import * as controller from './controller/controller.js'

const app = express();
app.use(express.json())     //for json requests parsing

export const port = 3000;

// Endpoints

app.post('/shorten',controller.shorten)
app.get('/:alias', controller.getLongURLfromAlias)
app.get('/analytics/:alias',controller.analytics)
app.put('/update/:alias',controller.updateAlias)
app.delete('/delete/:alias',controller.deleteAlias)


// start app
app.listen(port,()=>{
    console.log(`Listening on port ${port} `);
    controller.ttlChecker();
})



