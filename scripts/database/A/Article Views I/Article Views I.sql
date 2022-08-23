-- Runtime: 377 ms (Top 88.16%) | Memory: 0 MB (Top 100.00%)
elect distinct author_id as id
from views
where author_id = viewer_id
order by id asc