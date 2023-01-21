-- 175. Combine Two Tables
SELECT 
p.firstName, p.lastName, city, state 
FROM Person p, ADDRESS a
WHERE p.personId = a.personId
UNION
SELECT firstName, lastName, NULL as city, NULL as state 
FROM Person p1
WHERE p1.personId NOT IN(
    SELECT p2.personId FROM Person p2, Address a1 
    WHERE p2.personId = a1.personId );