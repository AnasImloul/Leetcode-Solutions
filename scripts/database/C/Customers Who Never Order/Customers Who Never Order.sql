-- Runtime: 630 ms (Top 46.54%) | Memory: 999999999 MB (Top 100.00%)
SELECT Name as Customers from Customers
LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;