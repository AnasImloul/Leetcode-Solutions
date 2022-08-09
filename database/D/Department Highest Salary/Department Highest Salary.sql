SELECT b.Name AS Department, a.Name AS Employee, Salary FROM
(SELECT *, MAX(Salary) OVER(PARTITION BY DepartmentId) AS max_val
FROM Employee) a
JOIN Department b
ON a.DepartmentId = b.Id
WHERE Salary = max_val;
