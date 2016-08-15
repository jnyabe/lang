CS_SRCS = $(wildcard *.cs)
CPP_SRCS = $(wildcard *.cpp)
CPP_OBJS = $(CPP_SRCS:.cpp=.o)

DMCS = dmcs
GXX  = g++
AR   = ar

EXE  = test.exe
DLL  = testlib.so

all: $(EXE) $(DLL)

$(EXE): 
	$(DMCS) -out:$(EXE) $(CS_SRCS)

$(DLL): $(CPP_OBJS)
	$(GXX) -shared -o $(DLL) $(CPP_OBJS)

%.o:%.cpp
	$(GXX) -fPIC -c -o $@ $<

clean:
	$(RM) $(EXE)
