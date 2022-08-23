-- Runtime: 222 ms (Top 68.26%) | Memory: 0B (Top 100.00%)
elect id, movie, description, rating
from Cinema
where (id % 2) = 1 and description != "boring"
order by rating desc