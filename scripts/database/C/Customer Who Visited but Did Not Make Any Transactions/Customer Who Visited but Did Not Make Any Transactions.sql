-- Runtime: 932 ms (Top 99.13%) | Memory: 0 MB (Top 100.00%)
ELECT customer_id, COUNT(customer_id) AS count_no_trans
FROM Visits WHERE visit_id NOT IN(SELECT visit_id FROM Transactions)
GROUP BY customer_id;