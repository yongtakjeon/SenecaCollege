--Yongtak Jun, June/18/2020
SET AUTOCOMMIT ON;


-- 1)
CREATE TABLE L5_MOVIES
(
    mid         INT             PRIMARY KEY,
    title       VARCHAR(35)     NOT NULL,
    releaseYear INT             NOT NULL,
    director    INT             NOT NULL,
    score       DECIMAL(3,2),
    CONSTRAINT score_chk CHECK (score <5 AND score >0)
);


CREATE TABLE L5_ACTORS
(
    aid         INT             PRIMARY KEY,
    firstName   VARCHAR(20)     NOT NULL,
    lastName    VARCHAR(30)     NOT NULL
);


CREATE TABLE L5_CASTINGS
(
    movieid     INT,
    actorid     INT,
    PRIMARY KEY(movieid, actorid),
    CONSTRAINT casting_movie_fk FOREIGN KEY(movieid) REFERENCES L5_MOVIES(mid),
    CONSTRAINT casting_actor_fk FOREIGN KEY(actorid) REFERENCES L5_ACTORS(aid)
);

CREATE TABLE L5_DIRECTORS
(
    directorid  INT             PRIMARY KEY,
    firstname   VARCHAR(20)     NOT NULL,
    lastname    VARCHAR(30)     NOT NULL
);


-- 2)
ALTER TABLE L5_MOVIES
ADD CONSTRAINT movie_director_fk FOREIGN KEY (director) REFERENCES L5_DIRECTORS(directorid);

-- 3)
ALTER TABLE L5_MOVIES
ADD CONSTRAINT title_unique UNIQUE (title);

-- 4)
INSERT INTO L5_DIRECTORS VALUES (1010, 'Rob', 'Minkoff');
INSERT INTO L5_DIRECTORS VALUES (1020, 'Bill', 'Condon');
INSERT INTO L5_DIRECTORS VALUES (1050, 'Josh', 'Cooley');
INSERT INTO L5_DIRECTORS VALUES (2010, 'Brad', 'Bird');
INSERT INTO L5_DIRECTORS VALUES (3020, 'Lake', 'Bell');

INSERT INTO L5_MOVIES VALUES (100, 'The Lion King', 2019, 3020, 3.50);
INSERT INTO L5_MOVIES VALUES (200, 'Beauty and the Beast', 2017, 1050, 4.20);
INSERT INTO L5_MOVIES VALUES (300, 'Toy Story 4', 2019, 1020, 4.50);
INSERT INTO L5_MOVIES VALUES (400, 'Mission Impossible', 2018, 2010, 5.00);
INSERT INTO L5_MOVIES VALUES (500, 'The Secret Life of Pets', 2016, 1010, 3.90);

-- 5)
-- If the child table use the foreign key from the parent table,
-- the child table has to be deleted first
-- before the parent table is deleted.
DROP TABLE L5_CASTINGS;
DROP TABLE L5_MOVIES;
DROP TABLE L5_ACTORS;
DROP TABLE L5_DIRECTORS;


-- 6)
CREATE TABLE employee2 AS SELECT * FROM employees;

-- 7)
ALTER TABLE employee2
ADD username VARCHAR(50);

-- 8)
DELETE FROM employee2;

-- 9)
INSERT INTO employee2 (employeenumber, lastname, firstname, extension, email, officecode, reportsto, jobtitle)
SELECT * FROM employees;

-- 10)
UPDATE employee2 SET firstname = 'Yongtak', lastname = 'Jun'
WHERE employeenumber = 1002;

-- 11)
UPDATE employee2
SET username = LOWER(CONCAT(SUBSTR(firstname,0,1), lastname));

-- 12)
DELETE FROM employee2
WHERE officecode = 4;

-- 13)
DROP TABLE employee2;