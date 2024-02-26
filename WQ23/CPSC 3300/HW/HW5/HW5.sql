/*
1. (14 points, 2 points each) 
Given the structure and contents of the database that you built for courses, students, and registration 
of courses in homework #4, write SQL statements to answer questions below. 
*/
/*
(1) Which courses (course name, course credits) have been taken by the student with student ID 861103-
2438? 
*/
select courses.courseName, courses.credits
from students 
inner join registration 
on students.studentID = registration.studentID and students.studentID = '861103-2438'
inner join courses 
on courses.courseCode = registration.courseCode;

/*
(2) For students who have registered courses, how many credits has each student taken? In the query 
result, list student ID, student first name, student last name, and his/her credits. 
*/
select s.studentID, s.firstName, s.lastName, sum(c.credits)
from registration r
join students s
on s.studentID = r.studentID
join courses c
on c.courseCode = r.courseCode
group by s.studentID;

/* 
(3) First define a view that gives the student ID, student last name, student first name, and the grade 
average for each student who has registered courses.  Then use the view to find which students have 
the highest grade average. 
*/
create view v as
select s.studentID, s.lastName, s.firstName, avg(grade)
from students s
join registration r
on s.studentID = r.studentID
join courses c
on c.courseCode = r.courseCode
group by s.studentID
order by avg(grade) desc;

-- There is only one student who has the highest grade average
select * from v limit 1;

/* 
(4) Which students (student first name, student last name) have taken the course “Database Systems”? 
*/
select students.firstName, students.lastName
from students 
inner join registration 
on students.studentID = registration.studentID
inner join courses 
on courses.courseCode = registration.courseCode 
and courseName = 'Database Systems';

/*
(5) List all students (student first name, student last name) who have taken both “Database Systems” and 
“C++”. 
*/
select distinct s.firstName, s.lastName
from students s
join registration r
on s.studentID = r.studentID
join courses c
on c.courseCode = r.courseCode
and r.courseCode = (select courseCode from courses where courseName = 'Database Systems')
or r.courseCode = (select courseCode from courses where courseName = 'C++');

select courseCode from courses where courseName = 'Database Systems';
select courseCode from courses where courseName = 'C++';
select * from registration;

/* 
(6) List all students (student ID, student first Name, student last Name) and the courses (course name, 
course grade) that they have taken. If there are students who have not taken any course yet, the query 
result should reflect that (i.e. null for courseName, null for grade).    
*/
select distinct s.studentID, s.firstName, s.lastName, r.grade, c.courseName
from students s
left outer join registration r
on s.studentID = r.studentID
left outer join courses c
on c.courseCode = r.courseCode;

/*
(7) Find all students who have taken computer science courses (i.e. course codes CS***). For the result, 
list student first name, student last name, and the computer science course names that they have taken.  
*/
select distinct s.firstName, s.lastName, c.courseName
from students s
inner join registration r
on s.studentID = r.studentID
inner join courses c
on c.courseCode = r.courseCode and c.courseCode like 'CS%';

/*
2. (6 points, 2 points each) 
A database for inventory and transaction of Apple store has been developed. There are three tables in 
this database – Inventory, Transaction, Inventory_history. You can use the following script to create 
the tables.  
*/
create table inventory ( 
itemid varchar(20) primary key, 
name varchar(30), 
price decimal(6,2), 
quantity int 
); 
create table transaction ( 
transid int auto_increment primary key, 
itemid varchar(20), 
quantity int, 
time datetime, 
foreign key (itemid) references inventory(itemid) 
); 
create table inventory_history ( 
id int auto_increment primary key, 
itemid varchar(20), 
action varchar(20), 
oldprice decimal(6,2), 
time datetime, 
foreign key (itemid) references inventory(itemid) 
); 

/*
(1) Create a trigger “insert_inventory” on table “Inventory”. The trigger is fired after a row is inserted in 
table “Inventory”. After a row is inserted in table “inventory”, the “itemid”, the insertion time, and 
the action is inserted in table “Inventory_history”. The action is set to ‘add an item’. The oldprice is 
set to null. 
*/
delimiter $$ 
create trigger insert_inventory  
after insert on inventory 
for each row 
begin
insert into inventory_history
set itemid = new.itemid, action = 'add an item', oldprice = null, time = now();
end;$$ 
delimiter ;

/*
(2) Create a trigger “change_quantity” on table “Transaction”. The trigger is fired after a row is inserted 
in table “Transaction”. After a row is inserted in table “Transaction”, update the “quantity” in table 
“Inventory”. For example, if 3 iWatch are sold, then the quantity of iWatch in table “Inventory” is 
decreased by 3. 
*/
delimiter $$ 
create trigger change_quantity  
after insert on transaction 
for each row 
begin
update inventory
set quantity = quantity - new.quantity where itemid = new.itemid;
end;$$ 
delimiter ;
 
 /*
(3) Create a trigger “change_price” on table “Inventory”. The trigger is fired before a change is made to 
the “Inventory” table. Before the price of an item is changed, the “itemid”, the item’s old price, the 
action, and the time of change are inserted into the table “Inventory_history”.  The action is set to 
“price change”. 
*/
delimiter $$ 
create trigger change_price  
before update on inventory
for each row
begin
insert into inventory_history
set itemid = new.itemid, action = 'price change', oldprice = old.price, time = now();
end;$$ 
delimiter ; 
