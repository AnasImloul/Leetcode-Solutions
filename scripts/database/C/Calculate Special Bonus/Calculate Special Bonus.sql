-- Runtime: 536 ms (Top 85.07%) | Memory: 999999999 MB (Top 100.00%)
select employee_id,
case
    when employee_id%2 != 0 and name NOT LIKE 'M%' then salary
    else 0
end as bonus
from employees order by employee_id;