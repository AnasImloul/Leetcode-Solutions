-- Runtime: 315 ms (Top 86.36%) | Memory: 0B (Top 100.00%)
REATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N-1;
  RETURN (
      SELECT DISTINCT(salary) from Employee order by salary DESC
      LIMIT 1 OFFSET N

  );
END

#pls upvote if you find solution easy to undestand....!! Thanks..!!!