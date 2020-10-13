--Yongtak Jeon, June/4/2020


SET AUTOCOMMIT ON;

-- 1)
SELECT *
FROM offices;

-- 2)
SELECT employeenumber
FROM employees
WHERE officecode = 1;

-- 3)
SELECT customernumber, customername, contactfirstname, contactlastname, phone
FROM customers
WHERE city = 'Paris';

-- 4)
SELECT customernumber, customername, contactlastname||', '|| contactfirstname AS "lastname, firstname", phone
FROM customers
WHERE country = 'Canada';

-- 5)
SELECT DISTINCT(customernumber)
FROM payments
WHERE amount > 0;

-- 6)
SELECT customernumber, checknumber, amount
FROM payments
WHERE amount < 30000 OR amount > 65000
ORDER BY amount desc;

-- 7)
SELECT *
FROM orders
WHERE status = 'Cancelled';

-- 8)
SELECT productcode, productname, buyprice, msrp, msrp-buyprice AS markup, round(100 * (msrp-buyprice) / buyprice,1) AS percmarkup
FROM products;

-- 9)
SELECT *
FROM products
WHERE LOWER(productname)LIKE'%co%';

-- 10)
SELECT *
FROM customers
WHERE LOWER(contactfirstname)LIKE's%e%'

-- 11)
INSERT INTO employees
VALUES (1723, 'Jun', 'Yongtak', 'x1111', 'yjun4@myseneca.ca', 4, 1088, 'Cashier');

-- 12)
SELECT *
FROM employees
WHERE employeenumber = 1723;

-- 13)
UPDATE employees
SET jobtitle = 'Head Cashier'
WHERE employeenumber = 1723;

-- 14)
INSERT INTO employees
VALUES (1023, 'Leadbeatter', 'Zac', 'x111', 'zacy@myseneca.ca', 4, 1723, 'Cashier');

-- 15)
DELETE FROM employees
WHERE employeenumber = 1723;

-- 16)
DELETE FROM employees
WHERE employeenumber = 1023;

-- 17)
INSERT ALL
INTO employees VALUES (1723, 'Jun', 'Yongtak', 'x1111', 'yjun4@myseneca.ca', 4, 1088, 'Cashier')
INTO employees VALUES (1023, 'Leadbeatter', 'Zac', 'x111', 'zacy@myseneca.ca', 4, 1088, 'Cashier')
SELECT *
FROM dual;

-- 18)
DELETE FROM employees
WHERE employeenumber = 1723 OR employeenumber = 1023;