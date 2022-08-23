-- Runtime: 317 ms (Top 92.86%) | Memory: 0B (Top 100.00%)
ELECT ACTOR_ID, DIRECTOR_ID
    FROM ActorDirector
GROUP BY ACTOR_ID, DIRECTOR_ID
    HAVING COUNT(*) >= 3