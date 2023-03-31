-- In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

SELECT t1.movie_id
FROM
    (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = 'Johnny Depp')) t1
LEFT JOIN
    (SELECT movie_id FROM stars WHERE person_id IN (SELECT id FROM people WHERE name = 'Helena Bonham Carter')) t2
ON (t1.movie_id = t2.movie_id);