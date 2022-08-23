-- Runtime: 226 ms (Top 66.19%) | Memory: 999999999 MB (Top 100.00%)
SELECT * FROM cinema WHERE (id % 2 = 1) AND (description <> 'boring') ORDER BY rating DESC