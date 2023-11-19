use testdb;

CREATE TABLE customerInfo (
    Id INT,
    Name VARCHAR(20),
    address VARCHAR(20),
    phoneNumber varchar(20)
);

insert into customerInfo(Id, Name, address, phoneNumber)
Values
	(1,'pikachu','japan','010-1234-5678'),
	(2,'CaptainAmerica','USA','408-478-9919'),
	(3,'KungFupanda','China','006-1002-92'),
	(4,'QueenKnight','UK','447-873-7283');

-- To edit table size, check it first(use describe)
describe customerInfo;

Alter table customerInfo		-- Use alter to change column
Modify phoneNumber varchar(20) NOT NULL;

describe customerinfo;
insert into customerInfo(Id, Name, address, phoneNumber)
Values
	(1,'pikachu','japan','010-1234-5678'),
	(2,'CaptainAmerica','USA','408-478-9919'),
	(3,'KungFupanda','China','006-1002-92'),
	(4,'QueenKnight','UK','447-873-7283');

-- 'Alter' change the form of table. Use 'update' to change the data.
Alter table customerInfo
Modify Name varchar(30) NOT NULL;

insert into customerInfo(Id, Name, address, phoneNumber)
Values
	(1,'pikachu','japan','010-1234-5678'),
	(2,'CaptainAmerica','USA','408-478-9919'),
	(3,'KungFupanda','China','006-1002-92'),
	(4,'QueenKnight','UK','447-873-7283');

select * from customerInfo;

-- unique: As long as there are no duplicates. Blanks are allowed. Candidate key (candidate key that can be a primary key)
-- The primary key can distinguish each record. No spaces (NULL X)

-- Use 'alter table' to set 'primary key'
Alter table customerInfo
Add Primary Key(Id);

describe customerInfo;

-- An error occurred because a duplicate primary key value was intentionally entered.
insert into customerInfo(Id, Name, address, phoneNumber)
Values
	(3, 'KungFuPanda', 'China', '9930293');
    
create table shoppingInfo
(
	transactionNum int,
    Id int,
    price int,
    date Date,
    productCode varchar(4)
);

select * from shoppingInfo;

insert into shoppingInfo(transactionNum, Id, price, date, productCode)
Values
	(1042, 1, 44000, 20210711, 'k4l3'),
    (2123, 2, 58000, 20210826, 'j8o1'),
    (9012, 3, 129830, 20210914, 'a9w3'),
    (6178, 4, 810200, 20220719, 'i9q4');
    
select * from shoppingInfo;

Alter table shoppingInfo
Add Primary Key(Id);

describe shoppingInfo;

select * from shoppingInfo;




