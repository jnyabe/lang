SRCS = $(wildcard *.cs)

BIN = Test.dll

all: $(BIN)


$(BIN): $(SRCS)
	mcs -o:$(BIN) -t:library -r:nunit.framework, Test01.cs Test02.cs
#	mcs -t:library $(SRCS)

test:
	nunit-console Test.dll