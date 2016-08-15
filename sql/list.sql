DROP TABLE IF EXISTS content;
DROP TABLE IF EXISTS list;
DROP TRIGGER IF EXISTS remove_list;
CREATE TABLE IF NOT EXISTS content (
       	     id INTEGER PRIMARY KEY AUTOINCREMENT,
	     type INTEGER,
	     name TEXT
);


CREATE TABLE IF NOT EXISTS list (
       	     id INTEGER PRIMARY KEY AUTOINCREMENT,
	     list_id INTEGER,
	     idx INTEGER,
	     elem_id INTEGER,
	     name TEXT
);

CREATE TRIGGER remove_list 
AFTER 
      DELETE ON content 
BEGIN
      DELETE FROM list WHERE list.list_id = old.id;
END;

CREATE TRIGGER add_elem_list
BEFORE
	INSERT ON list
BEGIN
	UPDATE list SET idx = idx + 1 WHERE list_id = new.list_id AND idx >= new.idx;
END;

CREATE TRIGGER del_elem_list
AFTER
	DELETE ON list
BEGIN
	UPDATE list SET idx = idx - 1 WHERE list_id = old.list_id AND idx > old.idx;
END;

CREATE TRIGGER del_elem
AFTER
	DELETE ON content
BEGIN
	DELETE FROM list WHERE elem_id = old.id;
END;

INSERT INTO content (type, name) VALUES (1, 'music 1');
INSERT INTO content (type, name) VALUES (1, 'music 2');
INSERT INTO content (type, name) VALUES (1, 'music 3');
INSERT INTO content (type, name) VALUES (1, 'music 4');
INSERT INTO content (type, name) VALUES (1, 'music 5');
INSERT INTO content (type, name) VALUES (1, 'music 6');
INSERT INTO content (type, name) VALUES (1, 'music 7');
INSERT INTO content (type, name) VALUES (1, 'music 8');
INSERT INTO content (type, name) VALUES (1, 'music 9');
INSERT INTO content (type, name) VALUES (1, 'music 10');

INSERT INTO content (type, name) VALUES (1, 'music 11');
INSERT INTO content (type, name) VALUES (1, 'music 12');
INSERT INTO content (type, name) VALUES (1, 'music 13');
INSERT INTO content (type, name) VALUES (1, 'music 14');
INSERT INTO content (type, name) VALUES (1, 'music 15');
INSERT INTO content (type, name) VALUES (1, 'music 16');
INSERT INTO content (type, name) VALUES (1, 'music 17');
INSERT INTO content (type, name) VALUES (1, 'music 18');
INSERT INTO content (type, name) VALUES (1, 'music 19');
INSERT INTO content (type, name) VALUES (1, 'music 20');

INSERT INTO content (type, name) VALUES (2, 'list 1');
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 1, 1);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 2, 2);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 3, 3);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 4, 4);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 5, 5);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 6, 6);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 7, 7);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 8, 8);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 9, 9);
INSERT INTO list (list_id, idx, elem_id) VALUES (21, 10, 10);
INSERT INTO content (type, name) VALUES (2, 'list 2');
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 1,11);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 2,12);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 3,13);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 4,14);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 5,15);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 6,16);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 7,17);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 8,18);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 9,19);
INSERT INTO list (list_id, idx, elem_id) VALUES (22, 10,20);


