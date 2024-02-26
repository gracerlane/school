-- Query 1- inner join
-- Find all the games (games) that have Safari Ball.
select distinct g.games
from game_pair g
inner join list l
on g.games = l.games 
inner join pokeball b
on b.ball_name = l.ball_name and b.ball_name like 'Safari Ball';

-- Query 2- sum, count, avg, etc.
-- Find the number of Pokémon who have dual typing.
select count(national_number)
from pokemon
where type2 is not null;

-- Query 3- subquery
-- Find the Pokemon (national_number and name) that has the smallest national number in the Paldea region.
select name, national_number
from record 
where region_name = 'Paldea' 
and national_number = (select min(national_number) from record where region_name = 'Paldea');


-- Query 4- group by and having
-- Find the primary types that have more than 50 Pokemon with that primary type.
select type1, count(national_number)
from pokemon
group by type1
having count(national_number) > 50;


-- Query 5- left outer or right outer join
-- List the Pokemon (national_number and name) in the games and how many regions they’re in.
select p.national_number, p.name, count(r.region_name) as regions
from pokedex d
left outer join record r
on d.region_name = r.region_name
left outer join pokemon p
on p.national_number = r.national_number
group by p.national_number
order by p.national_number;


