-- Runtime: 1180 ms (Top 71.83%) | Memory: 0 MB (Top 100.00%)
ELECT s.name FROM SalesPerson s
    WHERE s.sales_id NOT IN (
        SELECT o.sales_id FROM Orders o LEFT JOIN Company c
            ON c.com_id=o.com_id
        WHERE c.name="RED"
    );