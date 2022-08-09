select name, 
sum(case when u.id = r.user_id then distance
else 0 end) as travelled_distance
from users u
left join rides r
on u.id = r.user_id
group by u.id
order by sum(distance) desc, name asc