--Yongtak Jun, June/11/2020

-- 1 - a)
SELECT employeenumber, firstname, lastname, city, phone, postalcode
FROM employees, offices
WHERE employees.officecode = offices.officecode AND country = 'France';
-- 1 - b)
SELECT employeenumber, firstname, lastname, city, phone, postalcode
FROM employees INNER JOIN offices
ON employees.officecode = offices.officecode AND country = 'France';

-- 2 - a)
SELECT *
FROM payments INNER JOIN customers
ON payments.customernumber = customers.customernumber AND customers.country = 'Canada'
ORDER BY payments.customernumber;
-- 2 - b)
SELECT payments.customernumber, customername, paymentdate, amount
FROM payments INNER JOIN customers
ON payments.customernumber = customers.customernumber AND customers.country = 'Canada';
-- 2 - c)
SELECT payments.customernumber, customername, TO_CHAR(paymentdate,'Mon dd, yyyy'), amount
FROM payments INNER JOIN customers
ON payments.customernumber = customers.customernumber AND customers.country = 'Canada';

-- 3)
SELECT customers.customernumber, customername
FROM customers LEFT OUTER JOIN payments
ON customers.customernumber = payments.customernumber
WHERE checknumber IS NULL AND country = 'USA'
ORDER BY customers.customernumber;

-- 4 - a)
CREATE VIEW vwCustomerOrder AS
SELECT customernumber, orders.ordernumber, orderdate, productname, quantityordered, buyprice
FROM orders INNER JOIN orderdetails ON orders.ordernumber = orderdetails.ordernumber
INNER JOIN products ON orderdetails.productcode = products.productcode;
-- 4 - b)
SELECT * FROM vwCustomerOrder;

-- 5)
SELECT *
FROM vwCustomerOrder v JOIN orderdetails o ON v.ordernumber = o.ordernumber
WHERE customernumber = 124
ORDER BY v.ordernumber, orderlinenumber;

-- 6)
SELECT customers.customernumber, contactfirstname, contactlastname, phone, creditlimit
FROM customers LEFT OUTER JOIN orders
ON customers.customernumber = orders.customernumber
WHERE ordernumber IS NULL;

-- 7)
CREATE VIEW vwEmployeeManager AS 
SELECT e.employeenumber, e.lastname, e.firstname, e.extension, e.email, e.officecode, e.reportsto, e.jobtitle, m.firstName ||' '|| m.lastname AS manager
FROM employees e LEFT OUTER JOIN employees m
ON e.reportsto = m.employeenumber;

-- 8)
CREATE OR REPLACE VIEW vwEmployeeManager AS
SELECT e.employeenumber, e.lastname, e.firstname, e.extension, e.email, e.officecode, e.reportsto, e.jobtitle, m.firstName ||' '|| m.lastname AS manager
FROM employees e INNER JOIN employees m
ON e.reportsto = m.employeenumber;

-- 9)
DROP VIEW vwCustomerOrder;
DROP VIEW vwEmployeeManager;
