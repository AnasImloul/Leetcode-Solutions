-- Runtime: 634 ms (Top 54.14%) | Memory: 999999999 MB (Top 100.00%)
select user_id,count(follower_id) 'followers_count'
from followers group by user_id order by 1;