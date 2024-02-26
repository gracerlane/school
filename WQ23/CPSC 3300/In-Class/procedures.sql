-- number 1 in handout
-- create table orders (
-- orderNumber int not null primary key,
-- status varchar(15) not null
-- );
-- insert into orders values 
-- (1, 'shipped'),
-- (2, 'resolved'),
-- (3, 'shipped'),
-- (4, 'cancelled'),
-- (5, 'in process'),
-- (6, 'in process');

-- drop procedure example;

-- delimiter $$
-- create procedure example(inout param1 varchar(15), inout number1 int)
-- begin
-- select count(param1) into number1 from orders
-- order by status;
-- end
-- $$

-- -- declare @param varchar(15);
-- set @param = 'shipped';
-- call example(@param, @number);
-- select @param, @number;




-- number 3 in handout
-- create table if not exists dictionary (
-- id int(11) auto_increment,
-- word varchar(100) not null,
-- meaning varchar(300) not null,
-- primary key (id)
-- );

-- delimiter $$
-- create procedure dummy(in w varchar(100), in m varchar(300))
-- begin
-- 	declare x int;
-- 	set x = 1;
-- 	while x <= 100 do
-- 		insert into dictionary(word, meaning) values (w, m);
-- 		set x = x+1;
-- 	end while;
-- end
-- $$

-- call dummy("a", "meaning");
-- select * from dictionary;


-- number 4 from handout
create table dataset (
id int(11),
word varchar(100) not null,
meaning varchar(300) not null,
primary key (id)
);

delimiter $$
create procedure number4(in w varchar(100), in m varchar(300))
begin
	declare x int;
	set x = 1;
	while x <= 100 do
		insert into dataset values (x, w, m);
		set x = x+1;
    if (x = 60) or (x = 80) then
			set x = x+1;
		end if;
	end while;
end
$$

-- delimiter $$
-- create procedure number4(in w varchar(100), in m varchar(300))
-- begin
-- 	declare x int;
-- 	set x = 1;
--   loop_label: loop
-- 		if x>= 100 then 
-- 			leave loop_label;
-- 		end if;
-- 		set x=x+1;
-- 		if(x=60) or (x=80) then
-- 			iterate loop_label;
-- 		else 
-- 			insert into dataset values (x, w, m);
-- 		end if;
--   end loop;
-- end
-- $$

call number4("a", "a meaning");
select * from dataset;

