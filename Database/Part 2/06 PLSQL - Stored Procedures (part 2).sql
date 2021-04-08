-- ***********************
-- Name: Yongtak Jun
-- Date: Mar/18/2021
-- ***********************

SET SERVEROUTPUT ON;

-- Question 1 --
-- The company wants to calculate what the employees¡¯ annual salary would be:
-- Do NOT change any salaries in the table.
-- Assume that the starting salary or sometimes called base salary was $10,000.
-- Every year of employment after that, the salary increases by 5%.
-- Write a stored procedure named calculate_salary which gets an employee ID from the user and for that employee,
-- calculates the salary based on the number of years the employee has been working in the company.
-- (Use a loop construct the calculation of the salary).
-- The procedure calculates and prints the salary.
-- If the employee does not exist, the procedure displays a proper message.

-- Q1 SOLUTION --
CREATE OR REPLACE PROCEDURE calculate_salary (empid IN NUMBER) AS
    salary         NUMBER := 10000;
    current_year   NUMBER := to_number(to_char(sysdate, 'YYYY'));
    
    v_firstname    employees.first_name%TYPE;
    v_lastname     employees.last_name%TYPE;
    hire_year      NUMBER;
BEGIN
    SELECT first_name, last_name, to_number(to_char(hire_date, 'YYYY'))
    INTO v_firstname, v_lastname, hire_year
    FROM employees
    WHERE employee_id = empid;

    LOOP
        hire_year := hire_year + 1;
        IF hire_year <= current_year THEN
            salary := salary * 1.05;
        END IF;
        EXIT WHEN hire_year > current_year;
    END LOOP;

    dbms_output.put_line('First Name: ' || v_firstname);
    dbms_output.put_line('Last Name: ' || v_lastname);
    dbms_output.put_line('Salary: ' || TO_CHAR(salary, '$99,999.00'));
EXCEPTION
    WHEN too_many_rows THEN
        dbms_output.put_line('Too Many Rows Returned!');
    WHEN no_data_found THEN
        dbms_output.put_line('No Data Found!');
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
END calculate_salary;
/


-- Question 2 --
-- Write a stored procedure named employee_works_here to print the employee_id, employee Last name and department name.
-- If the value of the department name is null or does not exist, display ¡°no department name¡±.
-- The value of employee ID ranges from your Oracle id's last 2 digits  (ex: dbs311_203g37 would use 37) to employee 105.
-- DO NOT USE CURSORS

-- Q2 SOLUTION --
CREATE OR REPLACE PROCEDURE employee_works_here AS
    
BEGIN
    dbms_output.put_line(RPAD('Employee #', 20, ' ') || RPAD('Last Name', 20, ' ') || RPAD('Department Name', 20, ' '));
    
    FOR i IN ( SELECT employee_id, last_name, department_name
                FROM employees e FULL OUTER JOIN departments d ON e.department_id = d.department_id
                WHERE employee_id BETWEEN 12 AND 105
                ORDER BY employee_id ASC ) LOOP
        dbms_output.put_line(RPAD(i.employee_id, 20, ' ') || RPAD(i.last_name, 20, ' ') || RPAD(NVL(i.department_name, 'no department name'), 20, ' '));
    END LOOP;

EXCEPTION
    WHEN OTHERS THEN
        dbms_output.put_line('There is an Error!');
        
END employee_works_here;
/