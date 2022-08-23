-- Runtime: 573 ms (Top 60.19%) | Memory: 999999999 MB (Top 100.00%)
with stats as (
  select
    Request_at,
    T.Status <> 'completed' as IsCancelled
  from Trips T
  join Users C on (Client_Id = C.Users_Id and C.Banned = 'No')
  join Users D on (Driver_Id = D.Users_Id and D.Banned = 'No')
  where
    Request_at between '2013-10-01' and '2013-10-03'
)
select
  Request_at as Day,
  Round(
    cast(sum(IsCancelled) as real) / cast(count(*) as real),
    2
  ) as 'Cancellation Rate'
from stats
group by Request_at
;