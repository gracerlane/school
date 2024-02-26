
drop procedure setRelocationFee;


delimiter |
create procedure setRelocationFee(IN employeeID int(11), OUT relocationfee double)
begin
   declare relocationcity varchar(50);
   select city into relocationcity
   from employees, offices
   where employees.officeCode = offices.officeCode
   and employeeNumber = employeeID;
    
   case relocationcity
     when 'San Francisco' then
        set relocationfee = 10000;
	 when 'Boston' then
		set relocationfee = 8000;
	 when 'London' then 
		set relocationfee = 20000;
     else  
        set relocationfee = 15000;
   end case;

end
|

delimiter ;

set @employeeID = 1501;
call setRelocationFee(@employeeID, @relocationfee);
select @employeeID, @relocationfee;
