create table project ( 
   proj_num char(2) not null, 
   proj_name varchar(50) not null, 
   proj_value decimal(12,2) not null, 
   proj_balance decimal(12,2) not null, 
   emp_num char(3) not null, 
   primary key(proj_num), 
   foreign key (emp_num) references employee(emp_num) 
on update cascade on delete cascade 
);

insert into project values ('15', 'Evergreen', 1453500.00, 1002350.00, '103'), 
('18','Amber Wave', 3500500.00, 2110346.00, '108'), 
('22', 'Rolling Tide', 805000.00, 500345.20, '102'), 
('25', 'Starlight', 2850500.00, 2309880.00, '107');

select * from project;