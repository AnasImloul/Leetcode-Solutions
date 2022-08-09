SELECT sub.employee_id
FROM (
	SELECT e.employee_id, name, salary
	FROM employees AS e
	LEFT JOIN salaries AS s
	ON e.employee_id = s.employee_id
	
	UNION
	
	SELECT s.employee_id, name, salary
	FROM employees AS e
	RIGHT JOIN salaries AS s
	ON e.employee_id = s.employee_id) AS sub
WHERE sub.name IS NULL OR sub.salary IS NULL
ORDER BY sub.employee_id
