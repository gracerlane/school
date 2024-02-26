create table odd (number int primary key);

delimiter |
create procedure insertOdd()
begin
  declare x int;
  set x = 0;
  loop_label: loop  
     if x >= 20 then
       leave loop_label;
	  end if;
     set x = x + 1;
     if (x mod 2) then
       if (x = 5) or (x = 15) then
         iterate loop_label;
	   else 
         insert into odd values (x);
	   end if;
     end if;
   end loop;
end
|



call insertOdd();



