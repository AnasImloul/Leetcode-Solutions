-- Runtime: 1215 ms (Top 62.25%) | Memory: 0 MB (Top 100.00%)
ELECT
        p.product_id, p.product_name
FROM
        product p
JOIN
        Sales s
ON
        p.product_id = s.product_id

GROUP BY s.product_id

      HAVING max(s.sale_date)<= '2019-03-31'
      AND MIN(s.sale_date)>='2019-01-01';