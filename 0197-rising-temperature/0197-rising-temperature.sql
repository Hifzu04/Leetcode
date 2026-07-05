# Write your MySQL query statement below

-- //The DATEDIFF(date1, date2) function calculates the number of days between two dates (date1 - date2).
select t.id from Weather t
inner join Weather y on  DATEDIFF(t.recordDate, y.recordDate) = 1
where t.temperature > y.temperature;



