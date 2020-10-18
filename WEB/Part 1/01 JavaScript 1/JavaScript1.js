/*********************************************************************************
* WEB222 – Assignment 01
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of
* this assignment has been copied manually or electronically from any other source (including web sites)
* or distributed to other students.
*
* Name: Yongtak Jun, Date: June/08/2020
*
********************************************************************************/


/*****************************
* Task 1
*****************************/
/*
a) Infinity: Infinity is displayed when a number exceeds the upper limit or mathematical error happens.
    ex. var number = 100/0;
        console.log(number);
b) Undefined: Undefined is displayed when the variable has not been assigned yet.
    ex. var variable;
        console.log(variable);
c) NaN: It stands for 'not a number'. It happens when we try to convert the variable which cannot be converted
        into number into number.
    ex. var number = "Hello";
        var parseNumber = parseInt(number);
        console.log(parseNumber);
*/

/*****************************
* Task 2
*****************************/
console.log(parseInt('1010',2));
console.log(parseInt('AF',16));
console.log(parseInt('713',8));

/*****************************
* Task 3
*****************************/
var celsius1 = 19.0;
var fahrenheit1 = celsius1*9/5+32;
console.log(celsius1+"C is "+fahrenheit1+"F");
var fahrenheit2 = 70.0;
var celsius2 = (fahrenheit2-32)*5/9;
console.log(fahrenheit2+"F is "+celsius2+"C");

/*****************************
* Task 4
*****************************/
function largerNum(num1, num2)
{
    var value;
    if(num1 >= num2)
    {
        value = num1;
    }
    else
    {
        value = num2;
    }
    return value;
}

var greaterNum = ((num1, num2)=>
{
    var value;
    if(num1 >= num2)
    {
        value = num1;
    }
    else
    {
        value = num2;
    }
    return value;
})

console.log("The larger number of 11 and 6 is "+largerNum(11,6));
console.log("The larger number of 59 and 77 is "+greaterNum(59,77));

/*****************************
* Task 5
*****************************/
function Evaluator()
{
    var sum = 0;

    for(var i = 0;i<arguments.length;i++)
    {
        sum += arguments[i];
    }
    return (sum/arguments.length >= 25);
}

console.log("Average grater than or equal to 25: "+Evaluator(25));
console.log("Average grater than or equal to 25: "+Evaluator(25,24));
console.log("Average grater than or equal to 25: "+Evaluator(25,24,26));

/*****************************
* Task 6
*****************************/

function showMultiples (num, numMutiples)
{
    for(var i = 1; i<=numMutiples; i++)
    {
        console.log(num + " x " + i + " = " + num*i);
    }
}

console.log("Multiples of the 7 from 1 to 7"); showMultiples(7,7);
console.log("Multiples of the 11 from 1 to 5"); showMultiples(11,5);
console.log("Multiples of the 15 from 1 to 3"); showMultiples(15,3);

/*****************************
* Task 7
*****************************/
function Increment()
{
    var counter = 100;
    return function()
    {
        counter+=100;
        return counter;
    };
}

var add = Increment();

var num = add();
num = add();
num = add();

console.log(num);