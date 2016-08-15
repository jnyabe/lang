LIB = Util.dll
EXE = test.exe
LIB_SRCS = $(wildcard *Util.cs)
EXE_SRCS = UtilTest.cs

GMCS = gmcs
MONO = mono
MONODOCER = monodocer
MCS = mcs

LIB_OPTS = -t:library -out:$(LIB)

all: $(EXE) 

$(EXE): $(LIB) $(EXE_SRCS)
	$(GMCS) -r:$(LIB) -out:$@ $(EXE_SRCS)

$(LIB): $(LIB_SRCS)
	$(GMCS) -doc:Util.xml $(LIB_OPTS)  $(LIB_SRCS)

doc: $(LIB)
	mdoc update -i Util.xml -o mdoc $(LIB)
	mdoc export-html -o html mdoc
clean:
	$(RM) $(LIB) $(EXE)
