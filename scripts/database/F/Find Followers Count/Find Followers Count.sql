-- Runtime: 523 ms (Top 76.41%) | Memory: 0B (Top 100.00%)
elect user_id,count(follower_id) 'followers_count'
from followers group by user_id order by 1;