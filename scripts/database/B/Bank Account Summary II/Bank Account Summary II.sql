SELECT u.name as name , SUM(t.amount) as balance 
FROM 
USERS u JOIN TRANSACTIONS t on u.account=t.account
GROUP BY 
t.ACCOUNT HAVING balance>10000;
