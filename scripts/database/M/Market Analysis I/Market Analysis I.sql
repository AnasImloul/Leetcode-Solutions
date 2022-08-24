-- Runtime: 1101 ms (Top 74.35%) | Memory: 0 MB (Top 100.00%)
ELECT u.user_id AS buyer_id ,u.join_date ,COUNT(o.buyer_id) AS orders_in_2019
FROM Users u LEFT JOIN Orders o
ON u.user_id = o.buyer_id AND YEAR(o.order_date) ='2019'
GROUP BY u.user_id