-- Pokedex (region_name, games) games is foreign key
select * from pokedex;

create table pokedex (
region_name varchar(7) not null primary key,
games varchar(35) not null,
foreign key (games) references game_pair(games) on update cascade on delete cascade
);

insert into pokedex values 
('Galar', 'Sword and Shield'),
('Sinnoh', 'Brilliant Diamond and Shining Pearl'),
('Paldea', 'Scarlet and Violet');