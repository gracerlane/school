/* 
1. (2 points) Write the SQL code that will create the table structures for the table Students, Courses, 
Registration, separately. The table structures are summarized below. 
*/
create table students (
studentID char(11) not null primary key,
firstName varchar(20) not null,
lastName varchar(20) not null,
gender char(1) not null,
dateofBirth date
);
create table courses (
courseCode varchar(6) not null primary key,
courseName varchar(70) not null,
level char(2),
credits int not null
);
create table registration (
studentID char(11),
courseCode varchar(6),
grade decimal(2,1) not null,
primary key (studentID, courseCode),
foreign key (studentID) references students(studentID) on update cascade on delete cascade,
foreign key (courseCode) references courses(courseCode) on update cascade on delete cascade
);

/*
2. (1 point) Write the SQL code to enter data in each table. 
*/
insert into students values ('861103-2438', 'Adam', 'Johnson', 'M', '1990-10-01'),
('911212-1746', 'Eva', 'Smith', 'F', '1991-08-20'),
('950829-1848', 'Anna', 'Washington', 'F', '1993-09-26'),
('123456-0980', 'Eric', 'Alonzo', 'M', '1990-05-26'),
('908023-2456', 'Bo', 'Ek', 'M', '1992-03-15'),
('098735-3456', 'Danny', 'Goss', 'M', '1992-02-01'),
('124345-3430', 'Mike', 'White', 'M', '1995-06-10'),
('124568-1345', 'Emily', 'Young', 'F', '1995-04-28'),
('908409-0010', 'Cathy', 'Lee', 'F', '1993-10-06'),
('124587-9088', 'Ben', 'Woo', 'M', '1992-11-30'),
('120953-0909', 'Anna', 'Washington', 'F', '1990-10-09'),
('120449-1008', 'John', 'Goss', 'M', '1995-10-26');
insert into courses values ('CS056', 'Database Systems', 'G1', 5),
('CS010', 'C++', 'U1', 5 ),
('ENG111', 'English', 'U1', 3), 
('FIN052', 'Finance', 'G1', 5),
('PHY210', 'Physics', 'U2', 5),
('CHE350', 'Chemistry', 'U3', 5), 
('BIO001', 'Biology', 'U1', 3),
('CS052', 'Operating Systems', 'G1', 5); 
insert into registration values ('861103-2438', 'CS056', 4),
('861103-2438', 'CS010', 4),
('861103-2438', 'PHY210', 3.5),
('911212-1746', 'ENG111', 2),
('950829-1848', 'CHE350', 3),
('950829-1848', 'BIO001', 2.5), 
('123456-0980', 'CS052', 3.5),
('123456-0980', 'CS056', 4), 
('908023-2456', 'PHY210', 3.0), 
('908023-2456', 'CS056', 1.0), 
('908023-2456', 'CS010', 2.0), 
('124345-3430', 'FIN052', 2.5), 
('124345-3430', 'CHE350', 4), 
('908409-0010', 'CS052', 2), 
('124587-9088', 'BIO001', 4), 
('124587-9088', 'CS052', 3.5);

/* 
3. (1 point) List the names (first name, last name) of all the students. Sort first by last name and 
then by first name alphabetically using one SQL statement.
*/
select firstName, lastName 
from students 
order by lastName, firstName;

/*
4. (1 point) What are the student ID, the names, and birthday of the female students who were 
born before the last day of 1992?
*/
select studentID, firstName, lastName, dateofBirth 
from students 
where gender = 'F' and dateofBirth < '1992-12-31';

/*
5. (1 point) How many students are registered in the course “PHY210”? 
*/
select count(studentID) 
from registration 
where courseCode = 'PHY210';

/*
6. (1 point) How many courses are offered by the department of Computer Science (i.e. course 
codes CS***)? 
*/
select count(courseCode) 
from courses 
where courseCode like 'CS%';

/*
7. (1 point) Which course(s) (couseCode and courseName) of level G1 give 5 credits? 
*/
select courseCode, courseName 
from courses 
where level = 'G1' and credits = 5;

/*
8. (1 point) How many courses are there on each level? 
*/
select level, count(distinct courseCode) 
from courses group by level;

/*
9. (1 point) What is the average grade of courses that have been taken by the student with 
student ID 861103-2438? 
*/
select studentID, avg(grade) 
from registration 
where studentID = '861103-2438';

/*
10. (1 point) Which students (studentID only) have the highest grade for the course ‘CS052’? 
*/
select studentID 
from registration 
where courseCode = 'CS052' and grade = (select max(grade) from registration where courseCode = 'CS052');

/* 
11. (1 point) Find the courses (course codes only) that have been taken by both the student 
861103-2438 and the student 123456-0980. 
*/
select distinct registration.courseCode from registration,
(select courseCode from registration where studentID = '861103-2438') S1, 
(select courseCode from registration where studentID = '123456-0980') S2
where registration.courseCode = S1.courseCode and S1.courseCode = S2.courseCode;

/*
12. (1 point) Find the students who have not registered any course yet. 
*/
select distinct students.studentID, students.firstName, students.lastName
from students 
left join registration on students.studentID = registration.studentID 
where registration.studentID is null;

/* 
13. (1 point) Find the student (studentID only), the sum of grade, and the average of grade, for 
each student who has registered courses and the average of grade is below 3. 
*/
select studentID, sum(grade), avg(grade)
from registration
group by studentID
having avg(grade) < 3;

/* 
14. (1 point) Find the student who has registered the most number of courses. If there are 
multiple students who have registered the most number of courses, just take one student (To 
take only one record - the 1st record in the returned result, use ‘limit 1’ at the end of your 
SQL code). 
*/
select studentID, count(courseCode) as count
from registration 
group by studentID
order by count desc
limit 1;

/*
15. (1 point) Find the students (studentID only) who have taken either “PHY210” or “BIO001”. 
*/
select studentID
from registration
where courseCode = 'PHY210' or courseCode = 'BIO001';

/* 
16. (1 point) Find the youngest student’s name. 
*/
select firstName, lastName
from students
where dateofBirth = (select min(dateofBirth) from students);


/* 
17. (1 point) How many students have NOT taken the course ‘CS056’? 
*/
select count(distinct studentID)
from students 
where studentID not in (select studentID from registration where courseCode = 'CS056' and courseCode is not null);


/*
18. (1 point) Change the credit for all Computer Science courses (i.e. course codes CS***) with 
five credits from 5 to 6. 
*/
update courses set credits = 6 where courseCode like 'CS%' and credits = 5;

select * from courses;

/*
19. (1 point) Delete the registration record for the student 908409-0010.
*/
delete from registration where studentID = '908409-0010';



select * from registration;

