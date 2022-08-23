-- Runtime: 411 ms (Top 66.00%) | Memory: 0B (Top 100.00%)
elect
   e1.name as Employee
from
   employee e1
   join
      employee e2
where
   e1.managerid = e2.id
   and e1.salary > e2.salary;