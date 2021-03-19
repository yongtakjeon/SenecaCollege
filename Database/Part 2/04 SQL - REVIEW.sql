-- 1)
-- For any customers with customer names that include 'Out', provide
-- (1) customer number, (2) customer name and (3) order number 
-- but only if they ordered any of these products -- 40301, 40303, 40310, 40306.  
-- Put result in order number order. 

SELECT cust_no, cname, order_no
FROM customers JOIN orders USING (cust_no)
JOIN orderlines USING (order_no)
WHERE cname LIKE '%Out%' AND prod_no IN (40301, 40303, 40310, 40306)
ORDER BY 3;



-- 2)
-- Display the (1) customer number, (2) customer name and (3) country code for all the customers that are in Canada. Look up the country code for Canada. Table used is CUSTOMERS
-- Please note that the user is to enter the 2 character country code AND that if they were doing Germany they could enter it as De, DE, eD as examples  meaning any combitaion.
-- Your SQL must allow for various user inputs of the code. Do not make the user enter it the way you want such as CA only. Be flexible and helpful.
-- Also do not use a lot of OR statements to get around the requirements.
-- NOTE: the user is not entering the country name.

SELECT cust_no, cname, country_cd
FROM customers
WHERE country_cd = UPPER('&Country_Code');



-- 3)
-- USE the ON method of join .. Be sure to layout the SQL in a readable format
-- Display all orders for United Kingdom. The COUNTRY_NAME can be either hard coded or accepted from the user -- your choice.BUT-- You need to have United Kingdom and not UK.  
-- Show only cities that start with T. 
-- Display the (1) customer number, (2) customer name, (3) address1, (4) order number, (5) product name,?(6) the total dollars for that line on the order.  
-- Give that last column the name of Line Sales
-- Put the output into?customer?number?order from highest to lowest. 
-- Display only customer numbers less than 1000 

SELECT
    o.cust_no,
    cname,
    address1,
    o.order_no,
    prod_name,
    price * qty "Line Sales"
FROM
    orders o
    JOIN customers c ON ( o.cust_no = c.cust_no )
    JOIN orderlines ol ON ( o.order_no = ol.order_no )
    JOIN products p ON ( ol.prod_no = p.prod_no )
    JOIN countries ct ON ( c.country_cd = ct.country_id )
WHERE
    country_name = 'United Kingdom'
    AND city LIKE 'T%'
    AND o.cust_no < 1000
ORDER BY
    1 DESC;



-- 4)
-- Find the total dollar value for all orders from London customers.
-- Each row will show (1) customer name, (2) order number and (3) total dollars for that order.
-- Sort by highest total first

SELECT c.cname, o.order_no, SUM(l.price*l.qty)
FROM customers c JOIN orders o ON (c.cust_no = o.cust_no)
JOIN orderlines l ON (o.order_no = l.order_no)
WHERE city = 'London'
GROUP BY c.cname, o.order_no
ORDER BY 3 DESC;



-- 5)
-- Mr. King, the AD_PRES is the top person in the company. He would like to see all orders in 2014 from Germany, Canada, Spain and Italy.
-- He would like to send advertising to them.  
-- Show the (1) customer number, (2)customer name (3) address1, (4) city and (5)country name

SELECT DISTINCT(c.cust_no), cname, address1, city, country_name
FROM orders o JOIN customers c ON (o.cust_no = c.cust_no)
JOIN countries ON (c.country_cd = countries.country_id)
WHERE order_dt LIKE '%2014' AND country_name IN ('Germany', 'Canada', 'Italy', 'Spain');



-- 6)
-- For all orders in the orders table supply order date and count of the number of orders on that date.
-- Only include those dates in 2014 and 2015
-- also only show those with more than 2 orders

SELECT order_dt, COUNT(order_no)
FROM orders
WHERE order_dt LIKE '%2014' OR order_dt LIKE '%2015'
GROUP BY order_dt
HAVING COUNT(order_no) > 2;



-- 7)
-- Display (1) Department_id, (2) Job_id and the (3) Lowest salary for this combination but only if that Lowest Pay falls in the range $5000 - $10,000.
-- Exclude people who
-- (a) work as some kind of Representative (REP)job from this query and
-- (b) departments IT and SALES -- you are given names so must use them
-- Sort the output according to the Department_id and then by Job_id.
-- You MUST NOT use the Subquery method.

SELECT e.department_id, job_id, MIN(salary)
FROM employees e JOIN departments d ON (e.department_id = d.department_id)
WHERE
    (job_id NOT LIKE '%REP') AND
    (department_name NOT IN ('IT', 'Sales'))
GROUP BY e.department_id, job_id
HAVING MIN(salary) BETWEEN 5000 AND 10000
ORDER BY 1, 2;



-- 8)
-- The President wants to know out of the 150 customers that are on file, how many customers have not placed an order.

SELECT COUNT(c.cust_no)
FROM customers c LEFT JOIN orders o ON (c.cust_no = o.cust_no)
WHERE order_no IS NULL;



-- 9)
-- Show what customers (1) number and (2) name along with the (3) country name
-- for all customers that are in the same countries as customers starting with the name Su.
-- Limit the list to any customer names that starts with the letters A to C. 

SELECT cust_no, cname, country_name
FROM customers JOIN countries ON (country_cd = country_id)
WHERE country_cd IN (SELECT country_cd
                        FROM customers
                        WHERE cname LIKE 'Su%')
AND cname BETWEEN 'A' AND 'Czzzzz';



-- 10)
-- List the (1) employee number, (2) last name (3) job id and (4) the modified or not modified salary for all employees.  
-- Show only employees -- If the salary without the increase is outside the range $6,000 - $11,000
-- and who are employed as a Vice Presidents or Managers (President is not counted here). You should use Wild Card characters for this.
-- the modified salary for a VP will be 30% higher
-- and managers a 20% salary increase.
-- Sort the output by the top salaries (before this increase).

SELECT employee_id, last_name, job_id,
        CASE WHEN job_id LIKE '%VP' THEN 1.30*salary
             WHEN job_id LIKE '%MAN' THEN 1.20*salary
             WHEN job_id LIKE '%MGR' THEN 1.20*salary
             ELSE salary
        END
FROM employees
WHERE
    (salary NOT BETWEEN 6000 AND 11000) AND
    (job_id LIKE '%VP' OR job_id LIKE '%MAN' OR job_id LIKE '%MGR')
ORDER BY salary DESC;



-- 11)
-- Display (1) last_name, (2) salary and (3) job for all employees who earn more than all lowest paid employees in departments outside the US locations.
-- Exclude President and Vice Presidents from this query.
-- This question may be interpreted as ALL employees in the table that are lower, OR comparing those in the US to the lowest outside the US. Choose whichever you want.
-- Sort the output by job title ascending.
-- You need to use a Subquery and Joining with the NEWER method. (USING/JOIN or ON)

SELECT last_name, salary, job_id
FROM employees
WHERE salary > ALL (SELECT MIN(salary)
                        FROM employees JOIN departments USING (department_id)
                        JOIN locations USING (location_id)
                        WHERE country_id <> 'US'
                        GROUP BY department_id)
AND job_id NOT IN ('AD_PRES', 'AD_VP')
ORDER BY 3;



-- 12)
-- List all the last names of all the managers and list the last name of any employees they manage.

SELECT m.last_name, e.last_name
FROM employees e JOIN employees m ON (e.manager_id = m.employee_id);



-- 13)
-- List the last names of he managers and how many they manage. Only show those who manage more than 2.

SELECT m.last_name, COUNT(e.last_name)
FROM employees e JOIN employees m ON (e.manager_id = m.employee_id)
GROUP BY m.last_name
HAVING COUNT(e.last_name) > 2;