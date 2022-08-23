-- Runtime: 538 ms (Top 71.52%) | Memory: 0B (Top 100.00%)
 Write your MySQL query statement below
select player_id, min(event_date) as first_login
from activity
group by player_id