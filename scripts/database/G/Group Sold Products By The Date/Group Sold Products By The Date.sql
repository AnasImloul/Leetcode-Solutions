-- Runtime: 365 ms (Top 94.59%) | Memory: 0B (Top 100.00%)
elect sell_date, count( DISTINCT product ) as num_sold ,

    GROUP_CONCAT( DISTINCT product order by product ASC separator ',' ) as products

        FROM Activities GROUP BY sell_date order by sell_date ASC;
