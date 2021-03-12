-- 1)
-- Write a SQL query to display the last name and hire date of all employees who were hired before the employee with ID 144 got hired.
-- Sort the result by the hire date with the employee that was there the longest going first on list.
SELECT last_name, hire_date
FROM employees
WHERE hire_date < (SELECT hire_date
                    FROM employees
                    WHERE employee_id = 144)
ORDER BY 2;


-- 2)
-- Write a SQL query to display the last name and salary of those employees with the lowest salary.
-- Sort the result by name.
SELECT last_name, salary
FROM employees
WHERE salary = (SELECT MIN(salary)
                FROM employees)
ORDER BY 1;


-- 3)
-- Write a SQL query to display the product number, product name, product type and sell price (prod_sell) of the highest selling price  product(s) in each product type.
-- Sort by product type.
SELECT prod_no, prod_name, prod_type, prod_sell
FROM products
WHERE (prod_type, prod_sell) IN (SELECT prod_type, MAX(prod_sell)
                                    FROM products
                                    GROUP BY prod_type)
ORDER BY 3;


-- 4)
-- Write a SQL query to display the product line,  and product sell price of the most expensive (highest sell price) product(s).
-- There may be more than 1 result.
SELECT prod_line, prod_sell
FROM products
WHERE prod_sell = (SELECT MAX(prod_sell)
                    FROM products);
                    

-- 5)
-- Write a SQL query to display product name and list price (Prod_sell) in product type Sleeping Bags
-- which has the list price less than the lowest list price in ANY product type. 
-- Sort the output by top list prices first and then by the product name.
SELECT prod_name, prod_sell
FROM products
WHERE prod_type = 'Sleeping Bags'
AND prod_sell < ANY (SELECT MIN(prod_sell)
                        FROM products
                        GROUP BY prod_type)
ORDER BY prod_sell DESC, prod_name;


-- 6)
-- Display (a) product number,(b)  product name, and (c) product type for products that are in the same product type as the product with the highest price.
SELECT prod_no, prod_name, prod_type
FROM products
WHERE prod_type = (SELECT prod_type
                    FROM products
                    WHERE prod_sell = (SELECT MAX(prod_sell)
                                        FROM products));
        
                                
-- 7)
-- Write a query to display the tomorrow¡¯s date in the following format:
-- January   06th of year 2021 <-- this is the format for the date you display.
SELECT TO_CHAR(sysdate + 1, 'Month ddth "of year" YYYY')
FROM dual;


-- 8)
-- Create a query that displays the (a) city names, (b) country codes or ID and (c) state/province names,
-- but only for those cities that start with a lower case S and have at least 8 characters in their name.
-- If city does not have a state name assigned, then put State Missing as your output on that row.
SELECT city, country_id, NVL(state_province, 'State Missing')
FROM locations
WHERE city LIKE 's%' AND LENGTH(city) > 7;