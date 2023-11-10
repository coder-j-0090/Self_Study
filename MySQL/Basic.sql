use gitSQL;


SELECT						-- It's like a filter
	name, age, weight		-- If you don't write all of them, not every information will be shown. Changing order in sql statement will change the order of shown information.
FROM
	monster
Where
	weight <= 200
Order by
	age asc;		-- Opposite is desc
    
Insert into monster(name, age, weight)		-- Adding new data
values
	("R",44,91),
    ("Meo",55,7),
    ("Pal",345,1299),
    ("Dia",555,2348),
    ("Gira",993,3456);		
    
-- To check if I saved it right 
SELECT 
    name, age, weight 
FROM
    monster
ORDER BY
	age asc;

set sql_safe_updates = 0; 		-- Workbench is setted to do one thing at a time, but if the user wants to do multiple things at once, then this statement force workbench to do so.

UPDATE monster 		-- Change the factor from the table monster.
SET 
    weight = weight+50
WHERE
	weight<=40;
    
-- Check
SELECT 
    name, age, weight 
FROM
    monster
ORDER BY
	age asc;

Delete From monster  		-- Workbench deletes by record, so every data in a row with chosen conditions will be deleted. For example, if you delete name using delete statement, age and weights will be deleted, too
Where age = 55;

-- Check
SELECT 
    name, age, weight 
FROM
    monster
ORDER BY
	age asc;


/*
 * Use 'select' to choose the range in the table
 * Use 'from' to choose the name of table
 * Use 'where' to set conditions
 * Use 'order by' to decide if the data will be shown in ascending or descending order
 * Use 'select distinct' to not repeat the original data
 * Use 'in' to see specific conditions
 * Use 'between a and b' to see the data inbetween a and b
 * Use 'null' because not-measured data can be 0, so if the user use 'null', it won't bring not-measured data
 * Use 'join' to connect a table to another table
 * Use 'group by' to make a group if it fits certain condition
 * Keep using select statement after each statement, so we can check if it worked well or not
*/
