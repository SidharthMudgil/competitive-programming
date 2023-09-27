-- 584. Find Customer Referee
SELECT name FROM Customer Where IFNULL(referee_id,0) <> 2; 