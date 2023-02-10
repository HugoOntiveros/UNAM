//Importamos las librarías requeridas
const express = require('express')
const bodyParser = require('body-parser')

//Documentación en https://expressjs.com/en/starter/hello-world.html
const app = express()

//Creamos un parser de tipo application/json
//Documentación en https://expressjs.com/en/resources/middleware/body-parser.html
const jsonParser = bodyParser.json()


app.get('/', function (req, res) {
    //Enviamos de regreso la respuesta
    res.setHeader('Content-Type', 'application/json');
    res.end(JSON.stringify({ 'status': 'ok' }));
})


//Creamos un endpoint de login que recibe los datos como json
app.post('/login', jsonParser, function (req, res) {
    //Imprimimos el contenido del body
    console.log(req.body);

//Valida que ninguno de los campos vengan vacíos
    if(req.body.email.length === 0) {
        res.setHeader('Content-Type', 'application/json');
        res.status(400).json({errorMessage:"Acceso no valido: correo requerido"});
    } else if (req.body.password.length === 0){
        res.setHeader('Content-Type', 'application/json');
        res.status(400).json({errorMessage: "Acceso no valido: contraseña requerida"});
    } else {
        res.setHeader('Content-Type', 'application/json');
        res.status(200).json({message: "Bienvenido"});
    }

})

//Corremos el servidor en el puerto 3000
const port = 3000;

app.listen(port, () => {
    console.log(`Aplicación corriendo en http://localhost:${port}`)
})
