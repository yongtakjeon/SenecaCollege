/*********************************************************************************
*
*  Name: Yongtak Jun
*  Date: Apr/08/2021
*
*  Online (Heroku) Link: https://yongtak-jun-first-heroku.herokuapp.com/
*
********************************************************************************/


var data = require("./data-service.js");
var dataServiceAuth = require("./data-service-auth.js");
var express = require("express");
const multer = require("multer");
const bodyParser = require('body-parser');
var path = require("path");
const fs = require("fs");
const exphbs = require('express-handlebars');
const clientSessions = require("client-sessions");


var app = express();

var HTTP_PORT = process.env.PORT || 8080;

app.use(function (req, res, next) {
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
});

app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: 'main',
    helpers: {
        navLink: function (url, options) {
            return '<li' +
                ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
                '><a href="' + url + '">' + options.fn(this) + '</a></li>';
        },
        equal: function (lvalue, rvalue, options) {
            if (arguments.length < 3)
                throw new Error("Handlebars Helper equal needs 2 parameters");
            if (lvalue != rvalue) {
                return options.inverse(this);
            } else {
                return options.fn(this);
            }
        }
    }
}));
app.set('view engine', '.hbs');

app.use(express.static('./public'));
app.use(bodyParser.urlencoded({ extended: true }));

// Setup client-sessions
app.use(clientSessions({
    cookieName: "session", // this is the object name that will be added to 'req'
    secret: "Yongtak Jun", // this should be a long un-guessable string.
    duration: 2 * 60 * 1000, // duration of the session in milliseconds (2 minutes)
    activeDuration: 1000 * 60 // the session will be extended by this many ms each request (1 minute)
  }));

  // custom middleware to add "session" to all views (res)
  app.use(function(req, res, next) {
    res.locals.session = req.session;
    next();
  });
  
// This is a helper middleware function that checks if a user is logged in
function ensureLogin(req, res, next) {
    if (!req.session.user) {
      res.redirect("/login");
    } else {
      next();
    }
}
  

function onHTTPStart() {
    console.log("Express http server listening on " + HTTP_PORT);
};


const storage = multer.diskStorage({
    destination: "./public/images/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});

const upload = multer({ storage: storage });

app.get("/", function (request, response) {
    response.render("./home");
});

app.get("/about", function (request, response) {
    response.render("./about");
});

app.get("/employees/add", ensureLogin, function (request, response) {
    data.getDepartments()
        .then((data) => {
            response.render("./addEmployee", { departments: data });
        })
        .catch(() => {
            response.render("./addEmployee", { departments: [] });
        });

});

app.get("/images/add", ensureLogin, function (request, response) {
    response.render("./addImage");
});

app.get("/departments/add", ensureLogin, function (request, response) {
    response.render("./addDepartment");
});



app.get("/images", ensureLogin, function (request, response) {
    fs.readdir("./public/images/uploaded", (err, data) => {
        response.render("images", { imgs: data });
    })
});

app.get("/employees", ensureLogin, function (req, res) {
    if (req.query.status) {
        data.getEmployeesByStatus(req.query.status)
            .then((employees) => {
                if (employees.length > 0)
                    res.render("employees", { employees: employees });
                else
                    res.render("employees", { message: "no results" });
            })
            .catch((err) => {
                res.render("employees", { message: err });
            });
    }
    else if (req.query.department) {
        data.getEmployeesByDepartment(req.query.department)
            .then((employees) => {
                if (employees.length > 0)
                    res.render("employees", { employees: employees });
                else
                    res.render("employees", { message: "no results" });
            })
            .catch((err) => {
                res.render("employees", { message: err });
            });
    }
    else if (req.query.manager) {
        data.getEmployeesByManager(req.query.manager)
            .then((employees) => {
                if (employees.length > 0)
                    res.render("employees", { employees: employees });
                else
                    res.render("employees", { message: "no results" });
            })
            .catch((err) => {
                res.render("employees", { message: err });
            });
    }
    else {
        data.getAllEmployees()
            .then((employees) => {
                if (employees.length > 0)
                    res.render("employees", { employees: employees });
                else
                    res.render("employees", { message: "no results" });
            })
            .catch((err) => {
                res.render("employees", { message: err });
            });
    }

});

app.get("/employee/:empNum", ensureLogin, (req, res) => {

    // initialize an empty object to store the values
    let viewData = {};

    data.getEmployeeByNum(req.params.empNum)
        .then((data) => {
            if (data) {
                viewData.employee = data; //store employee data in the "viewData" object as "employee"
            } else {
                viewData.employee = null; // set employee to null if none were returned
            }
        }).catch(() => {
            viewData.employee = null; // set employee to null if there was an error 
        }).then(data.getDepartments)
        .then((data) => {
            viewData.departments = data; // store department data in the "viewData" object as "departments"

            // loop through viewData.departments and once we have found the departmentId that matches
            // the employee's "department" value, add a "selected" property to the matching 
            // viewData.departments object

            for (let i = 0; i < viewData.departments.length; i++) {
                if (viewData.departments[i].departmentId == viewData.employee.department) {
                    viewData.departments[i].selected = true;
                }
            }

        }).catch(() => {
            viewData.departments = []; // set departments to empty if there was an error
        }).then(() => {
            if (viewData.employee == null) { // if no employee - return an error
                res.status(404).send("Employee Not Found");
            } else {
                res.render("./employee", { viewData: viewData }); // render the "employee" view
            }
        });
});

app.get("/employees/delete/:empNum", ensureLogin, (req, res) => {
    data.deleteEmployeeByNum(req.params.empNum)
        .then(() => {
            res.redirect("/employees");
        })
        .catch((err) => {
            res.status(500).send("Unable to Remove Employee / Employee not found");
        });
})


app.get("/departments", ensureLogin, function (request, response) {
    data.getDepartments()
        .then((departments) => {
            if (departments.length > 0)
                response.render("./departments", { departments: departments });
            else
                response.render("./departments", { message: "no results" });
        })
        .catch((err) => {
            let errMsg = { message: err };
            response.json(errMsg);
        })
});

app.get("/department/:departmentId", ensureLogin, (req, res) => {
    data.getDepartmentById(req.params.departmentId)
        .then((department) => {
            if (department)
                res.render("./department", { department: department });
            else
                res.status(404).send("Department Not Found");

        })
        .catch((err) => {
            res.status(404).send("Department Not Found");
        });
})

app.get("/departments/delete/:departmentId", ensureLogin, (req, res) => {
    data.deleteDepartmentById(req.params.departmentId)
        .then(() => {
            res.redirect("/departments");
        })
        .catch((err) => {
            res.status(500).send("Unable to Remove Department / Department not found");
        });
})

app.get("/login", (req, res)=>{
    res.render("./login");
});

app.get("/register", (req, res)=>{
    res.render("./register");
});

app.get("/logout", (req, res)=>{
    req.session.reset();
    res.redirect('/');
});

app.get("/userHistory", ensureLogin, (req, res)=>{
    res.render("./userHistory");
})





app.post("/images/add", upload.single("imageFile"), ensureLogin, (req, res) => {
    res.redirect("/images");
});

app.post("/employees/add", ensureLogin, (req, res) => {
    data.addEmployee(req.body)
        .then(() => {
            res.redirect("/employees");
        })
        .catch((err) => {
            res.status(500).send("Unable to Create Employee");
        });

});

app.post("/employee/update", ensureLogin, (req, res) => {
    data.updateEmployee(req.body)
        .then(() => {
            res.redirect("/employees");
        })
        .catch((err) => {
            res.status(500).send("Unable to Update Employee");
        });

});

app.post("/departments/add", ensureLogin, (req, res) => {
    
    console.log(req.body);
    data.addDepartment(req.body)
        .then(() => {
            res.redirect("/departments");
        })
        .catch((err) => {
            res.status(500).send("Unable to Create Department");
        });

});

app.post("/department/update", ensureLogin, (req, res) => {
    data.updateDepartment(req.body)
        .then(() => {
            res.redirect("/departments");
        })
        .catch((err) => {
            res.status(500).send("Unable to Update Department");
        });

});

app.post("/register", (req, res)=>{
    dataServiceAuth.registerUser(req.body)
    .then(()=>{
        res.render("./register", {successMessage: "User created"});
    })
    .catch((err)=>{
        res.render("./register", {errorMessage: err, userName: req.body.userName} );
    });
});

app.post("/login", (req, res)=>{
    req.body.userAgent = req.get('User-Agent');

    dataServiceAuth.checkUser(req.body)
    .then((user) => {
        req.session.user = {
            userName: user.userName, // authenticated user's userName
            email: user.email, // authenticated user's email
            loginHistory: user.loginHistory // authenticated user's loginHistory
        }
        res.redirect('/employees');
    })
    .catch((err)=>{
        res.render("./login", {errorMessage: err, userName: req.body.userName} );
    });  
});


app.use(function (req, res, next) {
    res.status(404).sendFile(path.join(__dirname, "/views/404.gif"));
});



data.initialize()
    .then(dataServiceAuth.initialize)
    .then(function () {
        app.listen(HTTP_PORT, onHTTPStart);
    })
    .catch(function (err) {
        console.log("Failed to start. " + err);
    });