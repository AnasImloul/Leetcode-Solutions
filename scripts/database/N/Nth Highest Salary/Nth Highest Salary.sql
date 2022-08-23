-- Runtime: 418 ms (Top 57.78%) | Memory: 999999999 MB (Top 100.00%)
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      SELECT DISTINCT(salary) from Employee order by salary DESC
      LIMIT 1 OFFSET N

  );
END

#pls upvote if you find solution easy to undestand....!! Thanks..!!!