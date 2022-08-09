SELECT id, IFNULL(
					CASE WHEN MOD(id, 2) = 1 THEN LEAD(student,1) OVER() 
                    ELSE LAG(student,1) OVER() END, 
                    student
                  ) student
FROM seat;
