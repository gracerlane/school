create table assignment ( 
  assign_num char(4) not null, 
  assign_date date not null, 
  proj_num char(2) not null, 
  emp_num char(3) not null, 
  assign_job char(3) not null, 
  assign_chg_hr decimal(5,2) not null, 
  assign_hours decimal(3,1) not null, 
  primary key(assign_num), 
  foreign key(proj_num) references project(proj_num) on 
update cascade on delete cascade, 
  foreign key(emp_num) references employee(emp_num) 
on update cascade on delete cascade, 
  foreign key(assign_job) references job(job_code) on 
update cascade on delete cascade 
);

insert into assignment values ('1001', '2012-03-22', '18', '103', '500', 84.50, 3.5), 
('1002', '2012-03-22', '18', '102', '501', 84.50, 5.9), 
('1003', '2012-03-22', '25', '108', '501', 96.75, 2.2), 
('1004', '2012-03-22', '22', '102', '501', 96.75, 4.2), 
('1005', '2012-03-22', '18', '103', '500', 84.50, 0.9), 
('1006', '2012-03-23', '25', '107', '501', 105.00, 4.3),
('1007', '2012-03-23', '18', '108', '501', 96.75, 3.4),
('1008', '2012-03-23', '22', '104', '501', 96.75, 2.8),
('1009', '2012-03-23', '15', '103', '500', 84.50, 6.1 ),
('1010', '2012-03-23', '22', '105', '502', 105.00, 4.7 ),
('1011', '2012-03-24', '25', '106', '500', 110.50, 4.9 ),
('1012', '2012-03-24', '15', '101', '502', 125.00, 3.1 ),
('1013', '2012-03-24', '22', '108', '501', 110.50, 2.7 ),
('1014', '2012-03-24', '22', '105', '502', 125.00, 3.5 );

select * from assignment;

