(use sxml.serializer)
(define doc
  '(*TOP* (*PI* xml "version='1.0'")
	 (poem
	  (@ (title "The Lovesong of J. Alfred Prufrock")
	     (poet "T. S. Eliot"))
	  (stanza
	   (line "Let us go them, you and I,")
	   (line "When the evening is spread out against the sky")
	   (line "Like a patient etherized upon a table:"))
	  (stanza
	   (line "In the room the women come and go")
	   (line "Talking of Michaelangelo.")))))

(srl:sxml->xml doc (current-output-port))