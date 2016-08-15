CS_SRCS = $(wildcard *.cs)
EXE = PInvokeExample.exe

GMCS = gmcs
MONO = mono

all: $(EXE)

$(EXE): $(CS_SRCS)
	$(GMCS) -out:$(EXE) $(CS_SRCS)


clean:
	$(RM) $(EXE)
