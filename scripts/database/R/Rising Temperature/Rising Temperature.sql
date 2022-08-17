SELECT a.Id FROM Weather AS a, Weather AS b
WHERE DATEDIFF(a.Date, b.Date)=1 AND a.Temperature > b.Temperature
