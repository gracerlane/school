-- GamePair (year, games, gimmick, played_on) no foreign key
select * from game_pair;

create table game_pair (
games varchar(35) not null primary key,
year int not null,
gimmick varchar(15),
played_on varchar(15) not null
);

insert into game_pair values 
('Sword and Shield', '2019', 'Dynamax', 'Nintendo Switch'),
('Brilliant Diamond and Shining Pearl', '2021', 'N/A', 'Nintendo Switch'),
('Scarlet and Violet', '2022', 'Terastallize', 'Nintendo Switch');

