-- Runtime: 823 ms (Top 64.39%) | Memory: 999999999 MB (Top 100.00%)
elect name,
sum(case when u.id = r.user_id then distance
else 0 end) as travelled_distance
from users u
left join rides r
on u.id = r.user_id
group by u.id
order by sum(distance) desc, name asc