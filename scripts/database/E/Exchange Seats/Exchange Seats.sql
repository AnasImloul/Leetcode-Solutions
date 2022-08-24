-- Runtime: 226 ms (Top 99.70%) | Memory: 999999999 MB (Top 100.00%)
ELECT id, IFNULL(
                    CASE WHEN MOD(id, 2) = 1 THEN LEAD(student,1) OVER()
                    ELSE LAG(student,1) OVER() END,
                    student
                  ) student
FROM seat;