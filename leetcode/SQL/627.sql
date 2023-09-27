-- 627. Swap Salary
UPDATE Salary SET sex = CASE sex WHEN 'm' THEN 'f' ELSE 'm' END;