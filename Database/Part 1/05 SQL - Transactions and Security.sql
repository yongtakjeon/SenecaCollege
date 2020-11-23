--Yongtak Jun, June/29/2020

-- (1) 4 most common ways that a transaction is started
-- 1) The user has established a new connection to the server and has a blank sheet ready to go, starts a new transaction.
-- 2) The user uses the BEGIN statement in Oracle SQL, this will start a new transaction.
-- 3) The user executes a COMMIT statement, the current transaction is commited, and a new transaction starts.
-- 4) The user executes ANY DDL statement(CREATE, ALTER, DROP). This automatically triggers an auto-commit of the current transaction and starts a new transaction.

-- (2)
CREATE TABLE newEmployees
AS SELECT * FROM employees
WHERE 1=2;

-- (3)
SET AUTOCOMMIT OFF;
SET TRANSACTION READ WRITE;

-- (4)
INSERT ALL
INTO newemployees VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newemployees VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newemployees VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newemployees VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newemployees VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

-- (5)
SELECT * FROM newemployees; -- 5 rows.

-- (6)
ROLLBACK;
SELECT * FROM newemployees; -- 0 rows.

-- (7)
INSERT ALL
INTO newemployees VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newemployees VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newemployees VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newemployees VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newemployees VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

COMMIT;

SELECT * FROM newemployees; -- 5 rows.

-- (8)
UPDATE newemployees
SET jobtitle = 'unknown';

-- (9)
COMMIT;

-- (10)
ROLLBACK;

-- a)
SELECT * FROM newemployees
WHERE jobtitle = 'unknown'; -- 5 rows.

-- b) The ROLLBACK command was not effective.
-- c) In task 6, since I did not use COMMIT command, the all rows which had been inserted was all deleted by ROLLBACK command.
--      However, this time, since I used COMMIT command, ROLLBACK command was not effective so that still there are 5 rows.

-- (11)
SET TRANSACTION READ WRITE;
DELETE FROM newemployees;

-- (12)
CREATE VIEW vwNewEmps AS
SELECT * FROM newemployees
ORDER BY lastname, firstname;

-- (13)
ROLLBACK;

-- a) 0 employees.
-- b) No, the ROLLBACK command was not effective. That is because when we executes any DDL statement(CREATE, ALTER, DROP),
--      the current transaction will be automatically commited, and starts a new transaction, so that there was nothing to rollback.

-- (14)
SET TRANSACTION READ WRITE;

INSERT ALL
INTO newemployees VALUES (100, 'Patel', 'Ralph', 22333, 'rpatel@mail.com', 1, NULL, 'Sales Rep')
INTO newemployees VALUES (101, 'Denis', 'Betty', 33444, 'bdenis@mail.com', 4, NULL, 'Sales Rep')
INTO newemployees VALUES (102, 'Biri', 'Ben', 44555, 'bbirir@mail.com', 2, NULL, 'Sales Rep')
INTO newemployees VALUES (103, 'Newman', 'Chad', 66777, 'cnewman@mail.com', 3, NULL, 'Sales Rep')
INTO newemployees VALUES (104, 'Ropeburn', 'Audrey', 77888, 'aropebur@mail.com', 1, NULL, 'Sales Rep')
SELECT * FROM dual;

-- (15)
SAVEPOINT insertion;

-- (16)
UPDATE newemployees
SET jobtitle = 'unknown';

SELECT * FROM newemployees;

-- (17)
ROLLBACK TO insertion;

SELECT * FROM newemployees;
-- Since I rolled back the transaction to the 'SAVEPOINT insertion', the UPDATE command was rolled back, so jobtitle's values are
--  all 'Sales Rep' like before.

-- (18)
ROLLBACK;

SELECT * FROM newemployees;
-- The new transaction was started at the task 14. That is why when ROLLBACK command was executed, the all transaction
--  from the task 14 was rolled back so that there is no data in the newEmployees table.

-- (19)
REVOKE ALL ON newemployees FROM PUBLIC;

-- (20)
GRANT SELECT ON newemployees TO dbs211_45;

-- (21)
GRANT INSERT, DELETE, UPDATE ON newemployees TO dbs211_45;

-- (22)
REVOKE ALL ON newemployees FROM dbs211_45;

-- (23)
DROP VIEW vwNewEmps;
DROP TABLE newemployees;