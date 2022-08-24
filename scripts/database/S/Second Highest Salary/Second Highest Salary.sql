-- Runtime: 239 ms (Top 69.60%) | Memory: 999999999 MB (Top 100.00%)
elect max(Salary) as SecondHighestSalary from Employee
where Salary < (select max(Salary) from Employee)