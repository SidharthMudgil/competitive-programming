## SQL Commands
This repository contains a collection of SQL problem solutions from various platforms.

## Problems

### 175. Combine Two Tables
```sql
SELECT p.firstName, p.lastName, city, state 
FROM Person p, ADDRESS a
WHERE p.personId = a.personId
UNION
SELECT firstName, lastName, NULL as city, NULL as state 
FROM Person p1
WHERE p1.personId NOT IN(
    SELECT p2.personId FROM Person p2, Address a1 
    WHERE p2.personId = a1.personId 
);
```

### 176. Second Highest Salary
```sql
SELECT IFNULL(
    (SELECT DISTINCT salary FROM Employee 
    ORDER BY salary DESC LIMIT 1 OFFSET 1),
    NULL
    ) AS SecondHighestSalary 
```

### 183. Customers Who Never Order
```sql
SELECT name as Customers FROM Customers WHERE id NOT IN (SELECT customerId from Orders);
```

### 196. Delete Duplicate Emails
```sql
DELETE P1 FROM Person P1, Person P2 WHERE P1.email = P2.email AND P1.id > P2.id;
```

###  584. Find Customer Referee
```sql
SELECT name FROM Customer Where IFNULL(referee_id,0) <> 2; 
```

### 595. Big Countries
```sql
SELECT NAME, POPULATION, AREA FROM WORLD WHERE AREA >= 3000000 OR POPULATION >= 25000000;
```

### 608. Tree Node
```sql
SELECT t.id, IF ( ISNULL(t.p_id), 'Root', IF ( 
	 t.id IN (SELECT p_id FROM tree),  'Inner', 'Leaf'
)) AS Type FROM Tree t;
```

### 627. Swap Salary
```sql
UPDATE Salary SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END;
```

### 1484. Group Sold Products By The Date
```sql
SELECT sell_date,
		COUNT(DISTINCT(product)) AS num_sold, 
		GROUP_CONCAT(DISTINCT product ORDER BY product ASC SEPARATOR ',') AS products
FROM Activities GROUP BY sell_date ORDER BY sell_date ASC;
```

### 1527. Patients With a Condition
```sql
SELECT patient_id, patient_name, conditions FROM Patients WHERE conditions LIKE "DIAB1%" OR conditions LIKE "% DIAB1%";
```

### 1667. Fix Names in a Table
```sql
SELECT user_id, CONCAT(UPPER(LEFT(name, 1)), LOWER(RIGHT(name, length(name) - 1))) as name FROM Users ORDER BY user_id;
```

### 1757. Recyclable and Low Fat Products
```sql
SELECT product_id FROM Products WHERE low_fats = 'Y' AND recyclable = 'Y';
```

### 1795. Rearrange Products Table
```sql
SELECT product_id, 'store1' as store, store1 as price FROM Products WHERE store1 IS NOT NULL
UNION
SELECT product_id, 'store2' as store, store2 as price FROM Products WHERE store2 IS NOT NULL
UNION
SELECT product_id, 'store3' as store, store3 as price FROM Products WHERE store3 IS NOT NULL;
```

### 1873. Calculate Special Bonus
```sql
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE 'm%') as bonus FROM Employees order by employee_id;
```
```sql
SELECT employee_id, salary as bonus FROM Employees WHERE employee_id % 2 <> 1 AND name NOT LIKE 'm%'
UNION
SELECT employee_id, 0 as bonus FROM Employees WHERE employee_id % 2 = 0 OR name LIKE 'm%';
```

### 1965. Employees With Missing Information
```sql
SELECT employee_id FROM Employees WHERE employee_id NOT IN (SELECT employee_id FROM Salaries)
UNION
SELECT employee_id FROM Salaries WHERE employee_id NOT IN (SELECT employee_id FROM Employees)
ORDER BY employee_id;
```
