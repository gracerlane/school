create table employee (  
   emp_num  char(3)  primary key,  
   emp_lname  varchar(15)  not null,  
   emp_fname  varchar(15)  not null,  
   emp_initial  char(1),  
   emp_hiredate  date,  
   job_code  char(3),  
   emp_year smallint, 
   foreign key (job_code) references  job(job_code) 
on update cascade on delete cascade 
);

insert into employee values ('101', 'News', 'John', 'G', '2000-11-08', '502', 12),
('102', 'Senior', 'David', 'H', '1989-07-12', '501', 23), 
('103','Arbough','June','E', '1996-12-01','500', 16), 
('104', 'Ramoras', 'Anne', 'K', '1987-11-15', '501', 25), 
('105', 'Johnson', 'Alice', 'K', '1993-02-01', '502', 19), 
('106','Smithfield', 'William', 'S', '2004-06-22', '500', 8), 
('107', 'Alonzo', 'Maria', 'D', '1993-10-10', '501', 8), 
('108', 'Washington', 'Ralph', 'B', '1991-08-22', '501', 21); 

select * from employee;