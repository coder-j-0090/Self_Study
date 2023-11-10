create database gitSQL;

use gitSQL;

create table if not exists monster
(
	name varchar(20) not null,
    age int,
    weight int
);

Describe monster;

Insert into monster(name, age, weight)
Values
    ("Pikachu",5,30),
    ("isanghye",6,28),
    ("ggobugi",5,40)
;
select * from monster;
