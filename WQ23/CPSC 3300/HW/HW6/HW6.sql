/*
1. We want to add a new sale order for the customer (customerNumber = 145) in the database. The 
steps of adding a sale order are described as follows: 
		1) Get latest sale order number from “orders” table, and use the next sale order number as 
		the new sale order number 
		2) Insert a new sale order into “orders” table for the customer (customerNumber = 145). For 
		this order, the orderNumber is the new sale order number from step 1), orderDate is the 
		current date (you can use now() to get the date), requiredDate is 5 days from now (you 
		can use date_add(now(), INTERVAL 5 DAY) to get the date), shippedDate is 2 days 
		from now (you can use date_add(now(), INTERVAL 2 DAY)  to get the date), status is 
		“in process”. 
		3) Insert new sale order items into “orderdetails” table. The customer has bought two items 
		in his order. One item has productCode = ‘S18_1749’, quantityOrdered = 30, priceEach 
		for this item is 136, orderLineNumber = 1. The second item has productCode = ‘S18_2248’, 
    quantityOrdered = 50, priceEach for this item is 55.09, orderLineNumber = 2. 
*/

start transaction;
select @newOrder := max(orderNumber) + 1 from orders;
insert into orders values (@newOrder, now(), date_add(now(), interval 5 day), date_add(now(), interval 2 day), 'in process', null, 145);
insert into orderdetails values (@newOrder, 'S18_1749', 30, 136, 1), (@newOrder, 'S18_2248', 50, 55.09, 2);
commit;


/*
2. Create a stored procedure “setRelocationFee” to set the relocation fee for a given employee. If 
the employee’s office is in San Francisco, the relocation fee is $10000; if the employee’s 
office is in Boston, the relocation fee is $8000; if the employee’s office is in London, the 
relocation fee is $20000; if the employee works in other offices, the relocation fee is $15000.  
Below is a sample statement to test your stored procedure. 
 
set @employeeID = 1501; 
call setRelocationFee(@employeeID, @relocationfee); 
select @employeeID, @relocationfee; 
*/

delimiter $$
create procedure setRelocationFee (in employeeID int, out relocationfee int)
begin
	select city from offices 
		where officeCode in 
			(select officecode from employees 
				where employeeNumber = employeeID) 
	into @empOffice;
	if @empOffice = 'San Francisco' then set relocationfee = 10000;
  elseif @empOffice = 'Boston' then set relocationfee = 8000;
  elseif @empOffice = 'London' then set relocationfee = 20000;
  else set relocationfee = 15000;
  end if;
end
$$


/*
3. Create a stored procedure “changeCreditLimit” to change the credit limit for a given 
customer. If the customer’s total payment amount (note: payment amount is in the table 
“payments”) is not smaller than a given amount, then add 2000 to the customer’s credit limit 
(note: credit limit is in the table “customers”). 
Below is a sample statement to test your stored procedure. 
 
set @customer = 114; 
set @totalpayment = 15000; 
call changeCreditLimit(@customer,@totalpayment); 
 
The current credit limit of customer “114” is 117300. After the procedure 
“changeCreditLimit” is invoked, the customer’s credit limit should become 119300. 
*/ 

delimiter $$
create procedure changeCreditLimit (in customer int, in totalPayment int)
begin
	select sum(totalPayment) from payments where customerNumber = customer into @total;
  if @total >= totalPayment then
		update customers
			set creditLimit = creditLimit + 2000 where customerNumber = customer;
	end if;
end
$$


/*
4. Create a table using the statement below. 
			create table odd (number int primary key); 
Then create a stored procedure “insertOdd” to insert odd numbers in the range of [1, 20] into the table 
“odd”. Number 5 and 15 are skipped.

Below is a statement to test your stored procedure. 
			call insertOdd(); 
*/

delimiter $$
create procedure insertOdd ()
begin
	declare x int;
	set x = 1;
	while x <= 20 do
		insert into odd values (x);
		set x = x+2;
    if (x = 5) or (x = 15) then
			set x = x+2;
		end if;
	end while;
end
$$
