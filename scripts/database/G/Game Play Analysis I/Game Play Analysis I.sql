-- Runtime: 806 ms (Top 31.02%) | Memory: 999999999 MB (Top 100.00%)
# Write your MySQL query statement below
select player_id, min(event_date) as first_login
from activity
group by player_id