-- 1)
-- Display the (1) employee_id,(2) First name Last name (as one name with a space between) and call the column Employee Name, (3) hire_date
-- Only show employees with hire dates in June 2016 to dates in December of 2016.  You cannot use >= or similar signs
-- Sort the output by top last hire_date first (December) and then by last name.
SELECT employee_id, first_name||' '||last_name AS "Employee Name", hire_date
FROM employees
WHERE hire_date BETWEEN TO_DATE('JUN/2016', 'MON/YYYY') AND TO_DATE('DEC/2016', 'MON/YYYY')
ORDER BY hire_date DESC, last_name;


-- 2)
-- Write a query to display the tomorrow¡¯s date. The result will depend on the day when you RUN/EXECUTE this query.  Label the column ¡°Next Day¡±.
SELECT sysdate + 1 AS "Next Day"
FROM dual;


-- 3)
-- Users will often use the name they are accustomed to using. You need to figure out what it is really called for the SQL to work.
-- Show the following 4 columns:  product ID, product name, list price (means selling price) , and the new list price if increased by 2%.
-- (a) Display a new list price (selling price) as a whole number.
-- (b) show only product numbers greater than 50000 and less than 60000
-- (c) show only product names that start with G or start with AS
SELECT prod_no, prod_name, prod_sell, ROUND(prod_sell * 1.02)
FROM products
WHERE (prod_no > 50000 AND prod_no < 60000)
AND (prod_name LIKE 'G%' OR prod_name LIKE 'AS%');


-- 4)
-- Display the job titles (job_id) and full names of employees whose first name contains an ¡®e¡¯ or ¡®E¡¯  anywhere, and also contains an 'a' or a 'g' anywhere.
SELECT job_id, first_name||' '||last_name
FROM employees
WHERE UPPER(first_name) LIKE '%E%' AND
    (first_name LIKE '%a%' OR first_name LIKE '%g%');
    
 
-- 5)
-- For employees whose manager ID is 124, write a query that displays the employee¡¯s Full Name and Job ID in the following format:
-- This is a sample:    Summer, Payne works as a Public Accountant
SELECT last_name||', '||first_name||' works as a '||job_id
FROM employees
WHERE manager_id = 124;


-- 6)
-- For each employee hired before October 2010, display
-- (a) the employee¡¯s last name, (b) hire date and (c) calculate the number of YEARS between TODAY and the date the employee was hired.
-- The output for column (c) should be to only 1 decimal place.
-- Put the output in order by column (c)
SELECT last_name, hire_date, ROUND(MONTHS_BETWEEN(sysdate, hire_date)/12, 1)
FROM employees
WHERE hire_date < TO_DATE('01-OCT-2010', 'DD-MON-YYYY')
ORDER BY 3;


-- 7)
-- Display each employee¡¯s last name, hire date, and the review date, which is the first Tuesday after a year of service, but only for those hired after 2018.
-- Label the column REVIEW DAY.
-- Format the dates to appear in the format like: TUESDAY, August the Thirty-First of year 2016
-- Sort by review date
SELECT
    last_name,
    hire_date,
    TO_CHAR(NEXT_DAY(ADD_MONTHS(hire_date,12),'TUESDAY'),
        'fmDAY, Month "the" Ddspth "of year" YYYY') AS "REVIEW DAY"
FROM employees
WHERE hire_date > TO_DATE('01-JAN-2018', 'DD-MON-YYYY')
ORDER BY 3;