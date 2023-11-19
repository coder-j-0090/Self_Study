use classicmodels;	-- This schema is the name of databse

describe employees;  
-- It shows the field, type, null, key, default, etc

select * from employees;


-- 조건율


select employeeNumber as e_number, lastName as name, jobTitle from employees;
-- Use 'as' to show what you want to see, and it defines the order of list in category.
-- Selection Statement is good so you can see data without editing original data.

select * from employees where officeCode <= 3;

select * from employees where officeCode in(2,4,6); 
select * from employees where officeCode = 2 or officeCode = 4;
-- If there are many conditions when you use 'where', use 'in' or 'or'.

select * from employees where reportsTo >=1000 and reportsTo<=1050;
select * from employees where reportsTo between 1000 and 1050;
-- These two lines above are same

select * from employees where lastname like "%k%";
-- You can use 'like' to come in front of the letter(s) you want or not. 
-- If % is in front, it means that there may be letters before it. If % is at the back, it means that there may be letters after it. 
-- If it is before or after it, it means that there may or may not be letters before or after it.

select * from employees where email like '_____@%';
-- Number of _ shows how many letters should will there be in front of the letter.

select * from employees where email like '%#%%' escape '#';
-- Use 'escape' to use special case.
-- You can use this when you want to find %. If you put # and % between two % and escape the #, % will be recognized as a character and can be used.


-- Aggregation Function : Use it to make a statistic about multiple rows.


select * from employees order by officeCode asc;
-- If I don't write 'asc', it won't be asc.
select count(*) as num_ppl, officecode from employees group by officeCode;
-- Use 'group by' to make a group of 'officeCode'

select count(*) from employees;
-- Count the number of employees

select *, if(officeCode=1, '인사부', if(officeCode=2, '총무부', '모르겠다')) as officeName from employees;

select officeCode, sum(reportsTo) as sum_reports from employees group by officeCode;
-- You have to write what to sum up when you use 'sum'

select officeCode, max(employeeNumber) as maxnum, min(employeeNumber) as minnum from employees group by officeCode;
-- Find the maximum and minimum values, use as to decide what to name the category at the top, get it from employees, and classify these max and min based on officeCode. 
-- Find the maximum and minimum values in each office code.

select officeCode, max(employeeNumber) as maxnum, min(employeeNumber) as minnum from employees group by officeCode having officeCode in (1,2,3);
-- Use 'having' when there should be conditions in group. Use 'where' for conditions in whole records. Use 'having' to set condition for certain group. 
-- To use 'having', there should be a group.

-- Nested Query
select officeCode, city, phone from offices where 
	officeCode in (select officeCode from employees where lastname like '%k%');
    
-- It's possible to call 'from offices' b/c it has the same database



