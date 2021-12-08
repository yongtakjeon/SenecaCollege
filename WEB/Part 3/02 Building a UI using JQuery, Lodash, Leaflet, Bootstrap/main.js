/* An user interface which is built in this assignment connects to the Assignment 1 Restaurants API. */

/*********************************************************************************
* WEB422 – Assignment 2
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Yongtak Student ID: 137350195 Date: June/09/2021
* Heroku API Link: https://web422assign77.herokuapp.com/
*
********************************************************************************/

// -------------------
// variables
// -------------------
let restaurantData = [];
let currentRestaurant = {}
let page = 1;
const perPage = 5;
let map = null;

// -------------------
// lodash template functions
// -------------------
// - template code for displaying restaurant data in the <table>
let tableRows = _.template(`
    <% for (let i = 0; i < resList.length; i++) { %>
        <tr data-id="<%- resList[i]._id %>" >
            <td><%- resList[i].name %></td>
            <td><%- resList[i].cuisine %></td>
            <td><%- resList[i].address.building %> <%- resList[i].address.street %></td>
            <td><%- avg(resList[i].grades) %></td>
        </tr>
    <% } %>
`)

// - template code for displaying a selected restaurant's name and address 
let nameAddressUI = _.template(`    
    <h4><%- curRes.name %></h4>
    <p><%- curRes.street %></p>
    <p><%- curRes.city %></p>
    <p><%- curRes.zip %></p>
`)

// - template code for displaying the ratings
let ratingsUI = _.template(`
    <% for (let i = 0; i < grades.length; i++) { %>
        <div class="panel panel-default">
            <div class="panel-heading">Rating from <%- grades[i].date.substring(0, 10) %></div>
            <div class="panel-body">
                <p>Grade: <%- grades[i].grade %> </p>
                <p>Score: <%- grades[i].score %> </p>
            </div>
        </div>
    <% } %>
`)

// -------------------
// other functions
// -------------------
// - calculates the average score of the restaurant
const avg = (grades) => {
    let totalScore = 0;

    for (let i = 0; i < grades.length; i++) {
        totalScore += grades[i].score;
    }

    return (totalScore / grades.length).toFixed(2);
}

// - retrieves data from API and populates the <table> element rows
const loadRestaurantData = () => {
    fetch(`https://web422assign77.herokuapp.com/api/restaurants?page=${page}&perPage=${perPage}`)
        .then((reponseObj) => {
            return reponseObj.json();
        }
        )
        .then((responseAsJson) => {
            restaurantData = responseAsJson;
            var html = tableRows({ resList: restaurantData });
            $("#restaurant-table > tbody").html(html);
        })
        .catch((err) => {
            console.log(err);
        });

}

// -------------------
// This function will run when the HTML page finishes loading
// -------------------
$(document).ready(function () {
    // write the code to:
    // - load restaurant data
    loadRestaurantData();

    // - implement the required event handlers     
    //      - clicking the NEXT button
    $("#btn-next").on("click", function () {
        page++;
        loadRestaurantData();
        //document.querySelector("#curr-page").innerHTML = `Current Page: ${page}`;
        $("#curr-page").html(`Current Page: ${page}`);
    });

    //      - clicking the PREV button
    $("#btn-prev").on("click", function () {
        if (page > 1) {
            page--;
            loadRestaurantData();
            // document.querySelector("#curr-page").innerHTML = `Current Page: ${page}`;
            $("#curr-page").html(`Current Page: ${page}`);
        }
    });

    //      - clicking a row
    $("#restaurant-table > tbody").on("click", "tr", function () {
        for (let i = 0; i < restaurantData.length; i++) {

            // Return the value of an attribute: $(selector).attr(attribute)
            if (restaurantData[i]._id == $(this).attr("data-id")) {
                currentRestaurant = restaurantData[i];

                // Show the location of the restaurant on map (using Leaflet)
                if (map !== null) {
                    map.remove()
                }
                map = new L.Map('leaflet', {
                    center: [currentRestaurant.address.coord[1], currentRestaurant.address.coord[0]],
                    zoom: 18,
                    layers: [
                        new L.TileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png')
                    ]
                });
                L.marker([currentRestaurant.address.coord[1], currentRestaurant.address.coord[0]]).addTo(map);

                // Show the restaurant's name, full address, city, and zip
                let details = {
                    name: currentRestaurant.name,
                    street: currentRestaurant.address.building + " " + currentRestaurant.address.street,
                    city: `${currentRestaurant.borough}, New York`,
                    zip: currentRestaurant.address.zipcode
                }
                $("#restaurant-details").html(nameAddressUI({ curRes: details }));

                // Show the restaurant's ratings
                $("#ratings-container").html(ratingsUI({ grades: currentRestaurant.grades }));
            }
        }
    });
})