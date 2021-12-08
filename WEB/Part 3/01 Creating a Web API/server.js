/*********************************************************************************
* WEB422 – Assignment 1
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Yongtak Jun Student ID: 137350195 Date: May/28/2021
* Heroku Link: https://web422assign77.herokuapp.com/
*
********************************************************************************/



// ################################################################################
// 1. Setup the web service 
// - import express, cors, mongoose, etc
// - configure the app variable
// ################################################################################
// Web service setup
const express = require("express")
const cors = require("cors")

const app = express()

// configure express to accept data from the client as JSON format
app.use(express.json())
// Add support for CORS
app.use(cors());


const HTTP_PORT = process.env.PORT || 8080


// ################################################################################
// 2. Importing the restaurantDB module and instanting a db variable
// ################################################################################
const RestaurantDB = require("./modules/restaurantDB.js")
const db = new RestaurantDB("mongodb+srv://dbUser:456654@cluster0.svjg9.mongodb.net/sample_restaurants?retryWrites=true&w=majority")


// ################################################################################
// 3. Endpoints
// ################################################################################
app.get("/", (req, res) => {
    res.json({ message: "Welcome to the restaurants API" })
})

app.post("/api/restaurants", (req, res) => {
    db.addNewRestaurant(req.body)
        .then((msg) => {
            res.status(201).json({ message: msg })
        })
        .catch(() => {
            res.status(500).send("Unable to Create a restaurant")
        });
});

app.get("/api/restaurants", (req, res) => {
    db.getAllRestaurants(req.query.page, req.query.perPage, req.query.borough)
        .then((restaurants) => {
            res.json(restaurants.map(value => value.toObject()))
        })
        .catch((errObj) => {
            res.status(500).send(errObj.name + ': ' + errObj.message)
        })
})

app.get("/api/restaurants/:restaurantID", (req, res) => {
    db.getRestaurantById(req.params.restaurantID)
        .then((restaurant) => {
            res.json(restaurant)
        })
        .catch(() => {
            res.status(500).send("Unable to find the Restaurant / Restaurant not found")
        });
})

app.put("/api/restaurants/:restaurantID", (req, res) => {
    db.updateRestaurantById(req.body, req.params.restaurantID)
        .then((msg) => {
            res.json({ message: msg })
        })
        .catch(() => {
            res.status(500).send("Unable to Update the restaurant")
        });
})

app.delete("/api/restaurants/:restaurantID", (req, res) => {
    db.deleteRestaurantById(req.params.restaurantID)
        .then((msg) => {
            res.status(204).json({ message: msg })
        })
        .catch(() => {
            res.status(500).send("Unable to Delete the restaurant")
        });
})


// ################################################################################
// 4. Tell the app to start listening for requests
// ################################################################################
db.initialize().then(() => {
    app.listen(HTTP_PORT, () => {
        console.log(`server listening on: ${HTTP_PORT}`);
    });
}).catch((err) => {
    console.log(err);
});