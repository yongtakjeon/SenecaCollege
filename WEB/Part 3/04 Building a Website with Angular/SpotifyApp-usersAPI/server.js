// Online Link to User API: https://spotify-users-api.herokuapp.com/

const express = require('express');
const cors = require("cors");
const jwt = require('jsonwebtoken');
const passport = require("passport");
const passportJWT = require("passport-jwt");
const dotenv = require("dotenv");

dotenv.config();

const userService = require("./user-service.js");

const app = express();

// JSON Web Token Setup
var ExtractJwt = passportJWT.ExtractJwt;
var JwtStrategy = passportJWT.Strategy;

// Configure its options
var jwtOptions = {};
jwtOptions.jwtFromRequest = ExtractJwt.fromAuthHeaderWithScheme("jwt");
jwtOptions.secretOrKey = process.env.JWT_SECRET;

var strategy = new JwtStrategy(jwtOptions, function (jwt_payload, next) {
    console.log('payload received', jwt_payload);

    if (jwt_payload) {
        // The following will ensure that all routes using 
        // passport.authenticate have a req.user._id & req.user.userName values 
        // that matches the request payload data
        next(null, {
            _id: jwt_payload._id,
            userName: jwt_payload.userName
        });
    } else {
        next(null, false);
    }
});

// tell passport to use our "strategy"
passport.use(strategy);

// add passport as application-level middleware
app.use(passport.initialize());


const HTTP_PORT = process.env.PORT || 8080;

app.use(express.json());
app.use(cors());





// --------------------------------
// ENDPOINTS
// --------------------------------

app.get("/", (req, res) => {
    res.send("This is users API of Yongtak Music application.");
});

app.post("/api/user/register", (req, res) => {
    userService.registerUser(req.body)
        .then((msg) => {
            res.json({ "message": msg });
        }).catch((msg) => {
            res.status(422).json({ "message": msg });
        });
});


// If the log in is successful, server will generate a Web token,
// and sends the token back to the client. 
app.post("/api/user/login", (req, res) => {
    userService.checkUser(req.body)
        .then((user) => {

            // This "payload" object will be the content of the
            // JWT sent back to the client.
            var payload = {
                _id: user._id,
                userName: user.userName
            };

            var token = jwt.sign(payload, jwtOptions.secretOrKey);

            // Web token is sent to the client
            res.json({ "message": "login successful", "token": token });

        }).catch((msg) => {
            res.status(422).json({ "message": msg });
        });
});

// obtaining the list of favourites for the user
app.get("/api/user/favourites", passport.authenticate('jwt', { session: false }), (req, res) => {

    // If the client provides the valid token, below data will be sent to the client.
    // Otherwise, error code 500 will be sent.
    userService.getFavourites(req.user._id).then((data) => {
        res.json(data);
    }).catch((msg) => {
        res.status(500).json({ "error": msg });
    });
});

// adding a specific favourite to the user's list of favourites
app.put("/api/user/favourites/:id", passport.authenticate('jwt', { session: false }), (req, res) => {

    userService.addFavourite(req.user._id, req.params.id).then((data) => {
        res.json(data);
    }).catch((msg) => {
        res.status(500).json({ "error": msg });
    });
});

// removing a specific favourite from the user's list of favourites
app.delete("/api/user/favourites/:id", passport.authenticate('jwt', { session: false }), (req, res) => {

    userService.removeFavourite(req.user._id, req.params.id).then((data) => {
        res.json(data);
    }).catch((msg) => {
        res.status(500).json({ "error": msg });
    });

});




userService.connect()
    .then(() => {
        app.listen(HTTP_PORT, () => { console.log("API listening on: " + HTTP_PORT) });
    })
    .catch((err) => {
        console.log("unable to start the server: " + err);
        process.exit();
    });