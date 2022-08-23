-- Runtime: 1404 ms (Top 54.65%) | Memory: 999999999 MB (Top 100.00%)
SELECT customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits WHERE visit_id NOT IN(SELECT visit_id FROM Transactions)
GROUP BY customer_id;