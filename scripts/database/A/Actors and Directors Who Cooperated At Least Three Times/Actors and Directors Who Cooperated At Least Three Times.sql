-- Runtime: 430 ms (Top 57.24%) | Memory: 999999999 MB (Top 100.00%)
select actor_id,director_id from ActorDirector group by 1,2 having count(*)>=3;