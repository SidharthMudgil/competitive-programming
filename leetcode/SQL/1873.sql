-- 1873. Calculate Special Bonus
SELECT employee_id, salary * (employee_id % 2) * (name NOT LIKE 'm%') as bonus FROM Employees order by employee_id;

SELECT employee_id, salary as bonus FROM Employees WHERE employee_id % 2 <> 1 AND name NOT LIKE 'm%'
UNION
SELECT employee_id, 0 as bonus FROM Employees WHERE employee_id % 2 = 0 OR name LIKE 'm%';