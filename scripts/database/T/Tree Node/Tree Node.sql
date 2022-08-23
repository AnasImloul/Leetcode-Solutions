-- Runtime: 537 ms (Top 50.01%) | Memory: 999999999 MB (Top 100.00%)
SELECT DISTINCT t1.id, (
    CASE
    WHEN t1.p_id IS NULL THEN 'Root'
    WHEN t1.p_id IS NOT NULL AND t2.id IS NOT NULL THEN 'Inner'
    WHEN t1.p_id IS NOT NULL AND t2.id IS NULL THEN 'Leaf'
    END
) AS Type
FROM tree t1
LEFT JOIN tree t2
ON t1.id = t2.p_id