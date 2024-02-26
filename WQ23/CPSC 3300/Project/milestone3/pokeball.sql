-- Poke Ball (ball_name, ball_description)
select * from pokeball;

create table pokeball (
ball_name varchar(15) not null primary key,
ball_description varchar(170) not null
);

insert into pokeball values 
('Beast Ball', 'A somewhat different Poke Ball that is not very effective when catching Pokemon.'),
('Cherish Ball', 'A quite rare Poke Ball made to commemorate a special occasion of some sort.'),
('Dive Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon in or on the water.'),
('Dream Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon that are asleep.'),
('Dusk Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon at night or in 
dark places, such as caves.'),
('Fast Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon that are 
usually very quick to run away.'),
('Feather Ball', 'A ball that flies fast and true. Ideal for catching nimble Pokemon or Pokemon that 
fly high in the air.'),
('Friend Ball', 'A somewhat different Poke Ball that makes a wild Pokemon more friendly toward you 
immediately after it''s caught.'),
('Gigaton Ball', 'The ultimate iteration of the Heavy Ball. A ball that is too heavy to fly high or far, 
but it is highly effective if you manage to hit an unsuspecting Pokemon.'),
('Great Ball', 'A good, high-performance Poke Ball that provides a higher success rate for catching Pokemon 
than a standard Poke Ball.'),
('Heal Ball', 'A remedial Poke Ball that restores HP and eliminates status conditions for a Pokemon caught with it.'),
('Heavy Ball', 'A somewhat different Poke Ball that becomes more effective the heavier the Pokemon is.'),
('Jet Ball', 'The ultimate iteration of the Feather Ball. A ball that flies fast and trueâ€”ideal for catching 
nimble Pokemon or Pokemon that fly high in the air.'),
('Leaden Ball', 'An improvement on the original Heavy Ball design. A ball that is too heavy to fly high or far, 
but it is highly effective if you manage to hit an unsuspecting Pokemon.'),
('Level Ball', 'A somewhat different Poke Ball that becomes more effective the lower the level of the Pokemon 
compared to your own Pokemon.'),
('Love Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon of the opposite 
gender to your own Pokemon.'),
('Lure Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon in or on the water.'),
('Luxury Ball', 'A particularly comfortable Poke Ball that makes a wild Pokemon quickly grow friendlier after 
being caught.'),
('Master Ball', 'The very best Poke Ball with the ultimate level of performance. With it, you will catch any 
wild Pokemon without fail.'),
('Moon Ball', 'A somewhat different Poke Ball that is more effective when catching Pokemon that can be evolved 
using a Moon Stone.'),
('Nest Ball', 'A somewhat different Poke Ball that becomes more effective the lower the level of the wild Pokemon.'),
('Net Ball', 'A somewhat different Poke Ball that is more effective when catching Water- or Bug-type Pokemon.'),
('Origin Ball', 'A singular and irreplicable Poke Ball that can be used to catch the frenzied Pokemon raging 
at the Temple of Sinnoh.'),
('Park Ball', 'A special Poke Ball used in the Pal Park.'),
('Poke Ball', 'A device for catching wild Pokemon. It''s thrown like a ball at a Pokemon, comfortably 
encapsulating its target.'),
('Premier Ball', 'A somewhat rare Poke Ball made to commemorate a special occasion of some sort.'),
('Quick Ball', 'A somewhat different Poke Ball that is more effective at catching Pokemon when used first 
thing in a battle.'),
('Repeat Ball', 'A somewhat different Poke Ball that is more effective when catching a Pokemon of a species 
that you''ve caught before.'),
('Safari Ball', 'A special Poke Ball used in locales such as the Safari Zone in the Kanto region and the 
Great Marsh in the Sinnoh region.'),
('Sport Ball', 'A special Poke Ball that was used during the Bug-Catching Contest in the Johto region.'),
('Strange Ball', ''),
('Timer Ball', 'A somewhat different Poke Ball that becomes more effective at catching Pokemon the more 
turns that are taken in battle.'),
('Ultra Ball', 'A mysterious ball that provides an even higher success rate for catching Pokemon than a 
Great Ball does.'),
('Wing Ball', 'An improvement on the original Feather Ball design. A ball that flies fast and true. 
It is ideal for catching nimble Pokemon or Pokemon that fly high in the air.');