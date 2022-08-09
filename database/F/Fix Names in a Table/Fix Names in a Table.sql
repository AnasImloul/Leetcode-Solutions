# Write your MySQL query statement below
SELECT user_id,CONCAT(UPPER(SUBSTR(name,1,1)),LOWER(SUBSTR(name,2,length(name)))) AS name
FROM Users ORDER BY user_id;
# SUBSTR(string_name , start_index ,end_index)

# second method 
SELECT user_id, concat(upper(LEFT(name, 1)), lower(RIGHT(name, length(name)-1))) as name
FROM users
ORDER BY user_id;
#RIGHT(name_of_string, no_of_charachters) 
===============   #👍Please do upvote if you got the solution ======================
