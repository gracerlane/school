delimiter |

create procedure changeCreditLimit(IN customerID int(11), IN total double)
begin
   declare totalexpense double;
   select sum(amount) into totalexpense
   from payments
   where customerNumber = customerID;
   
   if totalexpense >= total then
     update customers
     set creditLimit = creditLimit + 2000
	 where customerNumber = customerID;
   end if;
end
|

delimiter ;


set @customer = 114;
set @totalpayment = 15000;

call changeCreditLimit(@customer,@totalpayment);

set @customer = 114;
select customerNumber, creditLimit from customers
where customerNumber = @customer;
