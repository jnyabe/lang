DROP TABLE IF EXISTS counter;
DROP TRIGGER IF EXISTS countup;
CREATE TABLE IF NOT EXISTS counter (
       id INTEGER PRIMARY KEY,
       title TEXT,
       count INTEGER);

CREATE TRIGGER countup BEFORE INSERT ON counter 
       FOR EACH ROW WHEN NEW.title IN (SELECT title FROM counter)
BEGIN
       UPDATE counter SET count = count+1;
END;