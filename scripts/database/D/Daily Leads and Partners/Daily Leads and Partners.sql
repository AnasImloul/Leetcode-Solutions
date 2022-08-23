-- Runtime: 696 ms (Top 46.47%) | Memory: 999999999 MB (Top 100.00%)
select date_id, make_name, count(distinct lead_id) as unique_leads, count(distinct partner_id) as unique_partners
from dailysales
group by date_id, make_name;