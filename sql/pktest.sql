-- rowid is rowid
CREATE TABLE IF NOT EXISTS test_1 (
       name TEXT
);

-- rowid is id (auto increment) 
CREATE TABLE IF NOT EXISTS test_2 (
       id INTEGER PRIMARY KEY AUTOINCREMENT,
       name TEXT
);

-- rowid is id (no auto increment)
CREATE TABLE IF NOT EXISTS test_3 (
       id INTEGER PRIMARY KEY,
       name TEXT
);


insert into sqlite_sequence (name,seq) values ('test_1', 100000000);
insert into sqlite_sequence (name,seq) values ('test_2', 200000000);
insert into sqlite_sequence (name,seq) values ('test_3', 300000000);
