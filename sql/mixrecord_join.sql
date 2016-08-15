CREATE TABLE IF NOT EXISTS test_a (
       id_a INTEGER PRIMARY KEY AUTOINCREMENT,
       id_b INT,
       name TEXT
);

CREATE TABLE IF NOT EXISTS test_b (
       id_b INTEGER PRIMARY KEY AUTOINCREMENT,
       name TEXT
);

INSERT INTO test_a(id_b,name) VALUES (0, 'test0');
INSERT INTO test_a(id_b,name) VALUES (1, 'test1');
INSERT INTO test_a(id_b,name) VALUES (2, 'test2');
INSERT INTO test_a(id_b,name) VALUES (2, 'test3');
INSERT INTO test_a(id_b,name) VALUES (3, 'test4');
INSERT INTO test_a(id_b,name) VALUES (3, 'test5');
INSERT INTO test_a(id_b,name) VALUES (3, 'test6');

INSERT INTO test_b(name) VALUES ('b1');
INSERT INTO test_b(name) VALUES ('b2');
INSERT INTO test_b(name) VALUES ('b3');



