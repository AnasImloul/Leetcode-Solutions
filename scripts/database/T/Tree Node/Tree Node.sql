-- Runtime: 458 ms (Top 65.79%) | Memory: 0 MB (Top 100.00%)
ELECT id,

    CASE
        WHEN p_id IS NULL THEN 'Root'
        WHEN id IN (SELECT p_id FROM Tree)THEN 'Inner'
        ELSE 'Leaf'
        END AS type
 FROM Tree