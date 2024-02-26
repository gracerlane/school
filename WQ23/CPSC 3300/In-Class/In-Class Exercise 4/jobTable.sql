create table job ( 
   job_code char(3), 
   job_description varchar(50), 
   job_chg_hour decimal(5,2), 
   job_last_update  date, 
   primary key(job_code) 
);

insert into job values ('500', 'Programmer', 35.75, '2009-11-20'),
('501', 'System Analyst', 96.75, '2009-11-20'), 
('502', 'Database Designer', 125.00, '2010-03-24'), 
('503', 'Electrical Engineer', 84.50, '2009-11-20'); 

select * from job;