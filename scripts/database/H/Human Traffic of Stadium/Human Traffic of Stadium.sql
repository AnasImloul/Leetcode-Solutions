-- Runtime: 385 ms (Top 59.06%) | Memory: 0B (Top 100.00%)
ELECT DISTINCT t1.* -- remove duplicate rows
FROM stadium t1, stadium t2, stadium t3
WHERE t1.people >= 100 AND t2.people >= 100 AND t3.people >= 100
AND(
    (t1.id - t2.id = 1 and t1.id - t3.id = 2 and t2.id - t3.id =1) -- return id: 7,8
    OR (t2.id - t1.id = 1 and t2.id - t3.id = 2 and t1.id - t3.id =1) -- return id: 6,7
    OR (t3.id - t2.id = 1 and t2.id - t1.id =1 and t3.id - t1.id = 2) -- return id: 5,6
)
ORDER BY t1.id