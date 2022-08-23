-- Runtime: 359 ms (Top 39.61%) | Memory: 999999999 MB (Top 100.00%)
UPDATE salary
SET sex = CASE WHEN sex = 'm' THEN 'f' ELSE 'm' END