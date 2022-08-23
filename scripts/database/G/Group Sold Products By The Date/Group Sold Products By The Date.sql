-- Runtime: 537 ms (Top 51.43%) | Memory: 999999999 MB (Top 100.00%)
select sell_date, count( DISTINCT product ) as num_sold ,

    GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) as products

        FROM Activities GROUP BY sell_date order by sell_date ASC;