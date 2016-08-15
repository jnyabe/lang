target=test
objects=Main.class
manifest=MANIFEST.MF
SCALAFLAGS=-deprecation

all: $(target)

$(target): $(objects) $(mainfest)
	jar cfm $@ $(manifest) $(objects:%.class=%.scala) $.class scala
	chmod +x $@

%.class: %.scala
	scalac $(SCALACFLAGS) $<

clean:
	rm -f $(target)
	rm -f *.class

.PHONY: all clean
