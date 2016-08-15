CREATE TABLE IF NOT EXISTS test (
       name TEXT
);

INSERT INTO sqlite_sequence (name, seq) VALUES ('test', 100);

INSERT INTO test (name) VALUES ('text 1');
INSERT INTO test (name) VALUES ('text 2');
INSERT INTO test (name) VALUES ('text 3');
INSERT INTO test (name) VALUES ('text 4');
INSERT INTO test (name) VALUES ('text 5');
INSERT INTO test (name) VALUES ('text 6');
