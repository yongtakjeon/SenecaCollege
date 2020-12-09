// All you JavaScript code for assignment 4 should be in this file
// Name: Yongtak Jun, Dated: July/19/2020

window.onload = function () {
    var subtitle = document.querySelector("#subtitle");
    var table = document.querySelector("#outputTable");


    subtitle.innerHTML = "List of Countries and Dependencies";

    var tbody = document.createElement("tbody");

    for (var i = 0; i < countries.length; i++) {
        var tr = document.createElement("tr");
        var td = document.createElement("td");
        var img = document.createElement("img");
        img.src = "flags/" + countries[i].Code + ".png";
        img.alt = "";
        td.appendChild(img);
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].Code));
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].Name.English));
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].Continent));
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].AreaInKm2));
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].Population));
        tr.appendChild(td);
        td = document.createElement("td");
        td.appendChild(document.createTextNode(countries[i].Capital));
        tr.appendChild(td);

        tbody.appendChild(tr);
    }
    table.appendChild(tbody);



    var elem1 = document.querySelector("#menu_21");
    elem1.addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies - Population greater than 100 million";
        
        table.removeChild(tbody);
        //table.removeChild(table.querySelectorAll("tbody")[0]);
        //table.removeChild(table.querySelector("tbody"));
        //table.removeChild(document.getElementsByTagName("tbody")[0]);

        tbody = document.createElement("tbody");
        
        for (var i = 0; i < countries.length; i++) {
            if (countries[i].Population > 100000000) {
                var tr = document.createElement("tr");
                var td = document.createElement("td");
                var img = document.createElement("img");
                img.src = "flags/" + countries[i].Code + ".png";
                img.alt = "";
                td.appendChild(img);
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Code));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Name.English));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Continent));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].AreaInKm2));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Population));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Capital));
                tr.appendChild(td);

                tbody.appendChild(tr);
            }
        }
        table.appendChild(tbody);
    });


    var elem2 = document.querySelector("#menu_22");
    elem2.addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies - Population between 1 and 2 million";

        table.removeChild(tbody);

        tbody = document.createElement("tbody");
        for (var i = 0; i < countries.length; i++) {
            if (countries[i].Population >= 1000000 && countries[i].Population <= 2000000) {
                var tr = document.createElement("tr");
                var td = document.createElement("td");
                var img = document.createElement("img");
                img.src = "flags/" + countries[i].Code + ".png";
                img.alt = "";
                td.appendChild(img);
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Code));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Name.English));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Continent));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].AreaInKm2));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Population));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Capital));
                tr.appendChild(td);

                tbody.appendChild(tr);
            }
        }
        table.appendChild(tbody);
    });


    var elem3 = document.querySelector("#menu_31");
    elem3.addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies - Area greater than 1 million Km2, Americas";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
        for (var i = 0; i < countries.length; i++) {
            if (countries[i].Continent == "Americas" && countries[i].AreaInKm2 > 1000000) {
                var tr = document.createElement("tr");
                var td = document.createElement("td");
                var img = document.createElement("img");
                img.src = "flags/" + countries[i].Code + ".png";
                img.alt = "";
                td.appendChild(img);
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Code));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Name.English));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Continent));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].AreaInKm2));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Population));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Capital));
                tr.appendChild(td);

                tbody.appendChild(tr);
            }
        }
        table.appendChild(tbody);
    });

    var elem4 = document.querySelector("#menu_32");
    elem4.addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies - All countries in Asia";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
        for (var i = 0; i < countries.length; i++) {
            if (countries[i].Continent == "Asia") {
                var tr = document.createElement("tr");
                var td = document.createElement("td");
                var img = document.createElement("img");
                img.src = "flags/" + countries[i].Code + ".png";
                img.alt = "";
                td.appendChild(img);
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Code));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Name.English));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Continent));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].AreaInKm2));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Population));
                tr.appendChild(td);
                td = document.createElement("td");
                td.appendChild(document.createTextNode(countries[i].Capital));
                tr.appendChild(td);

                tbody.appendChild(tr);
            }
        }
        table.appendChild(tbody);
    });


  



    document.querySelector("#menu_41").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in English";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.English));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });


    document.querySelector("#menu_42").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Arabic";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Arabic));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });

    document.querySelector("#menu_43").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Chinese (中文)";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Chinese));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });


    document.querySelector("#menu_44").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in French";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Franch));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });


    document.querySelector("#menu_45").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Hindi";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Hindi));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });



    document.querySelector("#menu_46").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Korean";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Korean));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });


    document.querySelector("#menu_47").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Japanese";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Japanese));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });


    document.querySelector("#menu_48").addEventListener("click", function () {
        subtitle.innerHTML = "List of Countries and Dependencies – Country / Dep. Name in Russian";

        table.removeChild(tbody);
        tbody = document.createElement("tbody");
    
        for (var i = 0; i < countries.length; i++) {
            var tr = document.createElement("tr");
            var td = document.createElement("td");
            var img = document.createElement("img");
            img.src = "flags/" + countries[i].Code + ".png";
            img.alt = "";
            td.appendChild(img);
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Code));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Name.Russian));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Continent));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].AreaInKm2));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Population));
            tr.appendChild(td);
            td = document.createElement("td");
            td.appendChild(document.createTextNode(countries[i].Capital));
            tr.appendChild(td);
    
            tbody.appendChild(tr);
        }
        table.appendChild(tbody);
    });



    
}

