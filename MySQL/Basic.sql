-- inner join, outer join, left&right join
-- inner join shows the common factors of table a and table b 

SELECT 
    t1.employeeNumber AS ID,
    t1.lastName AS Name,
    t1.officeCode,
    t2.city
FROM
    employees t1
        INNER JOIN
    offices t2 ON t1.officeCode = t2.officeCode;
    
-- When there are two tables and the same ‘column’, connect the necessary parts in the overlapping part (on).
-- ‘inner join’ is the most important of ‘join’. It is similar in function to nested queries. I use this because it is faster than a nested query that finds the same thing and uses it as a condition to retrieve what is needed.

-- In ‘left join’, the table to be set on the left of the two tables becomes the main table. Inner join requires that the conditional clause following 'on' in the two tables matches the field in the two tables.
-- However, ‘left join’ does not have to satisfy both conditions.
-- For example, when using 'left join' on a shopping mall site, the left table is purchase information (name, purchase information, etc.) and the right table is the customer table. If the buyer is a non-member and there is no customer information in the customer table (right), the product is entered. You can have the address entered to receive delivery.

-- cross join: Cartesian product (when calculating mathematically). Used when creating a large amount of data. ex)AI







-- Key Constraints
-- Two tables

-- left
-- Primary key: A key that is always uniquely distinguishable from several other records. It must be unique. The moment the entered information overlaps, entry is not possible. It doesn't matter if you make several. Use candidate keys by prioritizing them.
-- Declare and specify ‘primary key’ separately later. When declaring ‘foreign key’

-- Right: I made it with the idea that it should be connected to the left. Office code on the left, office code on the right. The office code in the right table also has the characteristics of a primary key. To eliminate duplication of the left table, it was made to feel like a subtable. Because it is convenient to load and search data.
-- The center point is the left table. From the right perspective, the office code is the primary key. From the left table's perspective, the office code of the right table is the primary key that can be connected to my table (left) in another table. It is called a foreign key (from another table).
-- If one office code disappears from the right foreign key, the integrity of the data is violated. In the case of connection, a join statement appears in the query.

-- Use foreign keys appropriately. The query only has its joins wrong. However, if the table connection using a foreign key is incorrect, it will be difficult to find the mistake, so refrain from using it.

-- ‘constraint’ is a constraint. ‘foreign key constraint fail’ means an error occurs because the conditions are not met when using a foreign key.

-- Left Join
use testdb;

create table tb1(
	ID int,
    Realname varchar(10),
    memCode int Primary Key
);

insert into tb1(ID, Realname, memCode)
	Values
		(1,'Hong',1),
		(2,'sil',2),
        (3,'dong',3),
        (4,'yoon',4),
        (5,'seoak',5),
        (6,'yeoul',6);


create table tb2(
	memCode int Primary Key,
    -- join is not related to primary key
    color varchar(10)
);

insert into tb2(memCode, color)
	Values
		(1,'red'),
        (2,'orange'),
        (3,'yellow'),
        (4,'green');
        
select Realname, color from tb1 left join tb2 on tb1.memCode=tb2.memCode;

select Realname, color from tb2 right join tb1 on tb1.memCode = tb2.memCode;
