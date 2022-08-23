-- Runtime: 429 ms (Top 97.62%) | Memory: 0B (Top 100.00%)
*
So so as we know that we want to find out the number of unique leads
and the number of unique partners on a given date made by a given
maker therefore we will group the table on the basis of date_id and
make_name and then we will count the number of distinct lead_id
and partner_id
*/

SELECT date_id, make_name, COUNT(DISTINCT(lead_id)) AS unique_leads,
COUNT(DISTINCT(partner_id)) AS unique_partners FROM DailySales
GROUP BY date_id,make_name
