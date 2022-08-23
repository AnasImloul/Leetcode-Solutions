-- Runtime: 720 ms (Top 44.04%) | Memory: 999999999 MB (Top 100.00%)
SELECT T.employee_id
FROM
  (SELECT * FROM Employees LEFT JOIN Salaries USING(employee_id)
   UNION
   SELECT * FROM Employees RIGHT JOIN Salaries USING(employee_id))
AS T
WHERE T.salary IS NULL OR T.name IS NULL
ORDER BY employee_id;