-- Runtime: 381 ms (Top 65.69%) | Memory: 999999999 MB (Top 100.00%)
SELECT Email from Person
Group By Email
Having Count(*) > 1;