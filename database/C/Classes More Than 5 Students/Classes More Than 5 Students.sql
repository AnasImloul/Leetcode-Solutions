select class from courses
group by class 
HAVING count(distinct student) >= 5;
