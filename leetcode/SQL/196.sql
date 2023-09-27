-- 196. Delete Duplicate Emails
DELETE P1 FROM Person P1, Person P2 WHERE P1.email = P2.email AND P1.id > P2.id;