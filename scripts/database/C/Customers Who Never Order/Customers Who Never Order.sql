-- Runtime: 405 ms (Top 92.65%) | Memory: 0 MB (Top 100.00%)
ELECT Name as Customers from Customers
LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;