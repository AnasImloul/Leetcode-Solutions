select user_id,count(follower_id) 'followers_count'
from followers group by user_id order by 1;
