# Write your MySQL query statement below
select d.name as Department , e.name as Employee , salary as Salary 
from Employee e 
join  Department d  on e.departmentId = d.id
where (DepartmentId,Salary) in(
    select DepartmentId, max(Salary) from 
    Employee
    group by DepartmentId
)

