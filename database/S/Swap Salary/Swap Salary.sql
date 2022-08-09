UPDATE  salary
SET  sex = CASE WHEN sex = 'm' THEN 'f' ELSE 'm' END
