-- Runtime: 635 ms (Top 48.27%) | Memory: 999999999 MB (Top 100.00%)
SELECT
    event_day AS day,
    emp_id,
    SUM(out_time - in_time) AS total_time
FROM Employees
GROUP BY 1, 2