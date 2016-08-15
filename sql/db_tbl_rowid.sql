CREATE TABLE IF NOT EXISTS test1 (
       id INTEGER PRIMARY KEY,
       name TEXT,
       address TEXT,
       tel TEXT
);

CREATE TABLE IF NOT EXISTS test2 (
       id INTEGER PRIMARY KEY,
       name TEXT,
       address TEXT,
       tel TEXT
);

INSERT INTO test1 (name, address, tel) VALUES ('name1', 'address 1', '03-111-0001');
INSERT INTO test1 (name, address, tel) VALUES ('name2', 'address 2', '03-111-0002');
INSERT INTO test1 (name, address, tel) VALUES ('name3', 'address 3', '03-111-0003');
INSERT INTO test1 (name, address, tel) VALUES ('name4', 'address 4', '03-111-0004');
INSERT INTO test1 (name, address, tel) VALUES ('nmae5', 'address 5', '03-111-0005');
INSERT INTO test1 (name, address, tel) VALUES ('name6', 'address 6', '03-111-0006');
INSERT INTO test1 (name, address, tel) VALUES ('name7', 'address 7', '03-111-0007');
INSERT INTO test1 (name, address, tel) VALUES ('name8', 'address 8', '03-111-003');

INSERT INTO test2 (name, address, tel) VALUES ('name1', 'address 1', '03-222-0021');
INSERT INTO test2 (name, address, tel) VALUES ('name2', 'address 2', '03-222-0022');
INSERT INTO test2 (name, address, tel) VALUES ('name3', 'address 3', '03-222-0023');
INSERT INTO test2 (name, address, tel) VALUES ('name4', 'address 4', '03-222-0024');
INSERT INTO test2 (name, address, tel) VALUES ('name5', 'address 5', '03-222-0025');
INSERT INTO test2 (name, address, tel) VALUES ('name6', 'address 6', '03-222-0026');
INSERT INTO test2 (name, address, tel) VALUES ('name7', 'address 7', '03-222-0027');
INSERT INTO test2 (name, address, tel) VALUES ('name8', 'address 8', '03-222-0028');

