-- ***********************
-- Name: Yongtak Jun
-- Date: Feb/26/2021
-- ***********************

SET SERVEROUTPUT ON

-- 1)
-- Write a stored procedure that gets an integer number and prints
-- "The number is even." if a number is divisible by 2.
-- Otherwise, it prints "The number is odd."
CREATE OR REPLACE PROCEDURE evenodd (userinput IN NUMBER) AS
BEGIN
    IF MOD(userinput, 2) = 0 THEN
        dbms_output.put_line('The number is even.');
    ELSE
        dbms_output.put_line('The number is odd.');
    END IF;
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END evenodd;
/


-- 2)
-- Create a stored procedure named find_employee.
-- This procedure gets an employee number and prints the employee information.
-- The procedure displays a proper error message if any error occurs.
CREATE OR REPLACE PROCEDURE find_employee (userinput IN NUMBER) AS
    v_firstname   VARCHAR2(20 BYTE);
    v_lastname    VARCHAR2(25 BYTE);
    v_email       VARCHAR2(25 BYTE);
    v_phone       VARCHAR2(20 BYTE);
    v_hiredate    DATE;
    v_jobid       VARCHAR2(10 BYTE);
BEGIN
    SELECT first_name, last_name, email, phone_number, hire_date, job_id
    INTO v_firstname, v_lastname, v_email, v_phone, v_hiredate, v_jobid
    FROM employees
    WHERE employee_id = userinput;

    dbms_output.put_line('First name: ' || v_firstname);
    dbms_output.put_line('Last name: ' || v_lastname);
    dbms_output.put_line('Email: ' || v_email || '@myseneca.ca');
    dbms_output.put_line('Phone: ' || v_phone);
    dbms_output.put_line('Hire date: ' || to_char(v_hiredate, 'DD-MON-YY'));
    dbms_output.put_line('Job ID: ' || v_jobid);
EXCEPTION
    WHEN too_many_rows THEN
        dbms_output.put_line('Too Many Rows Returned!');
    WHEN no_data_found THEN
        dbms_output.put_line('No Data Found!');
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END find_employee;
/


-- 3)
-- Every year, the company increases the price of all products in one product type. 
-- For example, the company wants to increase the selling price of products in type Tents by $5. 
-- Write a procedure named update_price_tents to update the price of all products in the given type and the given amount to be added to the current selling price if the price is greater than 0.
-- The procedure shows the number of updated rows if the update is successful.
-- The procedure gets two parameters: Prod_type IN VARCHAR2, amount NUMBER(9,2)
CREATE OR REPLACE PROCEDURE update_price_tents (prodtype IN products.prod_type%type, amount IN NUMBER) AS
rows_updated number;

BEGIN
UPDATE products SET prod_sell = prod_sell + amount
WHERE prod_type = prodtype
AND prod_sell > 0;

rows_updated := SQL%rowcount;
    dbms_output.put_line('Number of updated rows : ' || rows_updated);
EXCEPTION
    WHEN no_data_found THEN
        dbms_output.put_line('No Data Found!');
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END update_price_tents;
/


-- 4)
-- Every year, the company increases the price of products by 1 or 2% based on if the selling price (prod_sell) is less than the average price of all products. 
-- Write a stored procedure named update_low_prices.
-- This procedure does not have any parameters. You need to find the average sell price of all products and store it into a variable of the same data type.
-- If the average price is less than or equal to $1000, then update the products selling price by 2% if that products sell price is less than the calculated average. 
-- If the average price is greater than $1000, then update products selling price by 1% if the price of the products selling price is less than the calculated average. 
-- The query displays an error message if any error occurs. Otherwise, it displays the number of updated rows.
CREATE OR REPLACE PROCEDURE update_low_prices AS
    rows_updated   NUMBER;
    avg_price      products.prod_sell%TYPE;
    percentage     NUMBER;
BEGIN
    SELECT AVG(prod_sell) INTO avg_price
    FROM products;

    IF avg_price <= 1000 THEN
        percentage := 1.02;
    ELSIF avg_price > 1000 THEN
        percentage := 1.01;
    END IF;

    UPDATE products SET prod_sell = prod_sell * percentage
    WHERE prod_sell < avg_price;

    rows_updated := SQL%rowcount;
    
    dbms_output.put_line('*** OUTPUT update_low_prices_137350195  STARTED ***
    
Number of updates: ' || rows_updated || '
    
-------- ENDED --------');
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END update_low_prices;
/


-- 5)
-- The company needs a report that shows three categories of products based their prices. The company needs to know if the product price is cheap, fair, or expensive.
-- Let us assume that
--	- If the list price is less than the (average sell price ? minimum sell price) divided by 2
--		The product¡¯s price is LOW.
--	- If the list price is greater than the (maximum price ? average price) divided by 2
--  	The product¡¯ price is HIGH.
--	- If the list price is between (average price ? minimum price) / 2  AND  (maximum price ? average price) / 2 INCLUSIVE
--  	The product¡¯s price is fair.
-- Write a procedure named price_report to show the number of products in each price category:
-- The following is a sample output of the procedure if no error occurs:
-- Low:  10
-- Fair: 50
-- High: 18  
-- The procedure has no parameter.
CREATE OR REPLACE PROCEDURE price_report AS
    avg_price    products.prod_sell%TYPE;
    min_price    products.prod_sell%TYPE;
    max_price    products.prod_sell%TYPE;
    low_count    NUMBER;
    fair_count   NUMBER;
    high_count   NUMBER;
BEGIN
    SELECT AVG(prod_sell), MIN(prod_sell), MAX(prod_sell)
    INTO avg_price, min_price, max_price
    FROM products;

    SELECT COUNT(*) INTO low_count
    FROM products
    WHERE prod_sell < ( avg_price - min_price ) / 2;

    SELECT COUNT(*) INTO high_count
    FROM products
    WHERE prod_sell > ( max_price - avg_price ) / 2;

    SELECT COUNT(*) INTO fair_count
    FROM products
    WHERE prod_sell BETWEEN ( avg_price - min_price ) / 2 AND ( max_price - avg_price ) / 2;

    dbms_output.put_line('Low:  ' || low_count);
    dbms_output.put_line('Fair: ' || fair_count);
    dbms_output.put_line('High: ' || high_count);
EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END price_report;
/
