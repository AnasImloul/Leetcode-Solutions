-- Runtime: 237 ms (Top 98.74%) | Memory: 0 MB (Top 100.00%)
elect class from courses
group by class
HAVING count(distinct student) >= 5;