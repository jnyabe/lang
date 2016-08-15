CS_SRCS = $(wildcard *.cs)
EXE = hello.exe

GMCS = gmcs
MONO = mono

all: $(EXE)

$(EXE): $(CS_SRCS)
	$(GMCS) -out:$(EXE) $(CS_SRCS)


clean:
	$(RM) $(EXE)
