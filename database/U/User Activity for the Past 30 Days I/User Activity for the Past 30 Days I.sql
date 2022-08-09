SELECT activity_date AS day, COUNT(DISTINCT user_id) AS active_users
FROM Activity;
