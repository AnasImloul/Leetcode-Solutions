-- Runtime: 1502 ms (Top 47.38%) | Memory: 999999999 MB (Top 100.00%)
SELECT u.user_id AS buyer_id ,u.join_date ,COUNT(o.buyer_id) AS orders_in_2019
FROM Users u LEFT JOIN Orders o
ON u.user_id = o.buyer_id AND YEAR(o.order_date) ='2019'
GROUP BY u.user_id