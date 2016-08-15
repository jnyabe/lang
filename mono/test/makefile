LIB = TestSet.dll
XML = ${LIB:.dll=.xml}
EXE = test.exe
LIB_SRCS = $(wildcard *Test.cs)
EXE_SRCS = TestMain.cs

GMCS = gmcs
MONO = mono


LIB_OPTS = -t:library -out:$(LIB)

all: $(EXE) 

$(EXE): $(LIB) $(EXE_SRCS)
	$(GMCS) -r:$(LIB) -out:$@ $(EXE_SRCS)

$(LIB): $(LIB_SRCS)
	$(GMCS) -doc:$(XML) $(LIB_OPTS)  $(LIB_SRCS)

doc: $(LIB)
	mdoc update -i $(XML) -o mdoc $(LIB)
	mdoc export-html -o html mdoc
clean:
	$(RM) $(LIB) $(EXE) $(XML)
