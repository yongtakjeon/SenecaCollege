-- 1)
-- For each job title (JOB_ID) display the job title and the number of employees with that same title. 
-- Change the job_title column to using an alias of your last name
-- Order from highest to lowest number of employees

SELECT job_id AS Jun, count(*)
FROM employees
GROUP BY job_id
ORDER BY 2 DESC;


-- 2)
-- Display the Highest, Lowest and Average salary.  
-- Add a column that shows the difference between the highest and lowest salaries.
-- Make sure the output looks meaningful to the user. EXAMPLE: Money should not be to 7 decimal places 
-- NOTE: DO NOT USE ALIAS COLUMN NAMES. 

SELECT
    TO_CHAR(MAX(salary), '$99,999.00'),
    TO_CHAR(MIN(salary), '$99,999.00'),
    TO_CHAR(AVG(salary), '$99,999.00'),
    TO_CHAR(MAX(salary) - MIN(salary), '$99,999.00')
FROM employees;


-- 3)
-- Display the customer name and the total amount the customer has ordered.
-- But only show those customers where the total exceeds 50,000
-- Order by lowest number first

SELECT c.cname, SUM(l.price*l.qty)
FROM customers c JOIN orders o ON (c.cust_no = o.cust_no)
JOIN orderlines l ON (o.order_no = l.order_no)
GROUP BY c.cname
HAVING SUM(l.price*l.qty) > 50000
ORDER BY 2;


-- 4)
-- Display the product type name and the total dollar sales for that product type.
-- The dollar sales column comes from these 2 columns called sales_2016 and sales_2015.
-- Order by product type

SELECT prod_type, SUM(sales_2015 + sales_2016)
FROM products
GROUP BY prod_type
ORDER BY prod_type;


-- 5)
-- For each customer display the name and the number of orders issued by the customer.
-- However, only show those customers beginning with an A. or a G
-- If the customer does not have any orders, the result will display 0.
-- Put in order by number of orders low to high.

SELECT c.cname, COUNT(o.order_no)
FROM customers c LEFT JOIN orders o ON (c.cust_no = o.cust_no)
WHERE c.cname LIKE 'A%' OR c.cname LIKE 'G%'
GROUP BY c.cname
ORDER BY 2;


-- 6)
-- Write a SQL query to show (a) cust_no, (b) cname (c) the total dollar sales (price * qty) and the total number of orders.
-- Put the output in order by -- the number of orders

SELECT c.cust_no, c.cname, SUM(l.price*l.qty), COUNT(o.order_no)
FROM customers c JOIN orders o ON (c.cust_no = o.cust_no)
JOIN orderlines l ON (o.order_no = l.order_no)
GROUP BY c.cust_no, c.cname
ORDER BY 4;


-- 7)
-- We are going to make the previous questions a little harder.
-- The user wanted all customers that have an UPPERCASE D anywhere in their name.
-- Show the customer even if they did not order anything.
-- Put output in order of column 4.

SELECT c.cust_no, c.cname, SUM(l.price*l.qty), COUNT(o.order_no)
FROM customers c LEFT JOIN orders o ON (c.cust_no = o.cust_no)
LEFT JOIN orderlines l ON (o.order_no = l.order_no)
WHERE c.cname LIKE '%D%'
GROUP BY c.cust_no, c.cname
ORDER BY 4;