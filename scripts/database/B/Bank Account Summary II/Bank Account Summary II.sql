-- Runtime: 517 ms (Top 98.58%) | Memory: 999999999 MB (Top 100.00%)
ELECT u.name as name , SUM(t.amount) as balance
FROM
USERS u JOIN TRANSACTIONS t on u.account=t.account
GROUP BY
t.ACCOUNT HAVING balance>10000;