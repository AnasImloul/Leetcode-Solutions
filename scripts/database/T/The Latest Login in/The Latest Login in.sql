-- Runtime: 780 ms (Top 46.93%) | Memory: 999999999 MB (Top 100.00%)
SELECT
    user_id,
    MAX(time_stamp) AS last_stamp #obtaining latest login for all users
FROM Logins
WHERE YEAR(time_stamp) = 2020 #filtering for login dates with year 2020 in timestamp
GROUP BY user_id;