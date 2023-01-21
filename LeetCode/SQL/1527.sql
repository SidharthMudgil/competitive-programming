-- 1527. Patients With a Condition
SELECT patient_id, patient_name, conditions FROM Patients WHERE conditions LIKE "DIAB1%" OR conditions LIKE "% DIAB1%";