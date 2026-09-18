-- Write your PostgreSQL query stateme
select Email
from Person
group by Email
having Count(Email)>1;