/*
* WEB222 Assignment 02
*
* I declare that this assignment is my own work in accordance with Seneca Academic Policy.
* No part of this assignment has been copied manually or electronically from any other source
* (including web sites) or distributed to other students.
*
* Name: Yongtak Jun
* Date: June/27/2020
*/


const users = require('./users.json');


function firstName()
{
    var firstUser = users[0];
    return firstUser.name.first;
}

//Task 1
function getAge(birthdate, currentdate)
{
    var age = currentdate.getFullYear() - birthdate.slice(0,4);

    if (currentdate.getMonth() < birthdate.slice(5,7)) age--;

    if (currentdate.getMonth() == birthdate.slice(5,7) && 
        currentdate.getDate() < birthdate.slice(8,10)) age--;

  return age;
}

console.log(getAge(users[0].birthDate,new Date()));


//Task 2
function getAvg(users)
{
    var ageSum = 0;
    for (var i=0; i<users.length;i++)
    {
        ageSum += getAge(users[i].birthDate,new Date());
    }
    return ageSum/users.length;
}

console.log(getAvg(users));


//Task 3
const userUtils = {};

userUtils.getManager = function(users)
{
    var managers = [];
    for(var i = 0; i<users.length;i++)
    {
        if(users[i].isManager == true)
        {
            managers.push(users[i]);
        }
    }
    return managers;
}

console.log(userUtils.getManager(users));


 //Task 4
function getNameLength(firstname,lastname)
{
    var fullname = firstname.concat(" "+lastname);
   return fullname.length;
}

userUtils.getLongestName = function(users)
{
    var length = 0, element = -1;

    for (var i = 0;i<users.length;i++)
    {
        if (getNameLength(users[i].name.first,users[i].name.last) > length)
        {
            length = getNameLength(users[i].name.first,users[i].name.last);
            element = i;
        }
    }

    return users[element];
}

console.log(userUtils.getLongestName(users));


//Task 5
userUtils.searchbyName = function(name, fuzzy)
{
    var searched = [];

    if(fuzzy == true)
    {
        var pattern = new RegExp('^'+name,'i');

        for (var i = 0;i<users.length;i++)
        {
            if(pattern.test(users[i].name.first) || pattern.test(users[i].name.last))
            {
                searched.push(users[i]);
            }
        }
    }
    else
    {
        for (var i = 0;i<users.length;i++)
        {
            if(users[i].name.first == name || users[i].name.last == name)
            {
              searched.push(users[i]);
            }
        }
    }
    
    return searched;
}

console.log(userUtils.searchbyName('pa',true));


//task 6
userUtils.mostCommonCountry = function(users)
{
    var countryList = [];
    var numOfcountry = [];
    var maxIndex = -1;

    for(var i = 0;i<users.length;i++)
    {
        if(!countryList.includes(users[i].address.country))
        {
            countryList.push(users[i].address.country);
        }
    }

    for(var i = 0;i<countryList.length;i++)
    {
        var num = 0;
        for(var j = 0;j<users.length;j++)
        {
            if(countryList[i] == users[j].address.country)
            {
                num++;
            }
        }
        numOfcountry.push(num);
    }
    
    for(var i = 0, maxNumber = 0;i<numOfcountry.length;i++)
    {
        if(numOfcountry[i] > maxNumber)
        {
            maxNumber = numOfcountry[i];
            maxIndex = i;
        }
    }
    return countryList[maxIndex] + " has the largest num";
}

console.log(userUtils.mostCommonCountry(users));