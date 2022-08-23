-- Runtime: 510 ms (Top 71.66%) | Memory: 0 MB (Top 100.00%)
ELECT
    event_day AS day,
    emp_id,
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY 1, 2