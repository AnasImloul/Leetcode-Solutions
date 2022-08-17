select d.Name as Department, e.Name as Employee, computed.Salary as Salary
from Employee e, 
	(
		select Salary, DepartmentId, @row := IF(DepartmentId=@did, @row + 1,1) as Rank , @did:=DepartmentId
		from (
			select distinct Salary, DepartmentId
			from Employee
			order by DepartmentId, Salary desc
			) ordered, (select @row:=0, @did:=0) variables
	) computed,
	Department d
where e.Salary=computed.Salary 
and e.DepartmentId=computed.DepartmentId 
and computed.DepartmentId=d.Id
and computed.Rank<=3
order by computed.DepartmentId, Salary desc
