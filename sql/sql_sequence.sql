CREATE TABLE IF NOT EXISTS test (
       id INTEGER PRIMARY KEY AUTOINCREMENT,
       t TEXT,
       b BLOB
);

INSERT INTO sqlite_sequence (name, seq) VALUES ('test', 10000);


INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));
INSERT INTO test(t,b) VALUES (quote(hex(randomblob(64))), randomblob(64));




