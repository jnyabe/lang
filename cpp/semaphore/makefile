SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
BIN  = test_sema

CPP = g++
CPPFLAGS = -g -O2


all: $(BIN)

$(BIN): $(OBJS)
	$(CPP) -o $@ $(OBJS)

%.o:%.cpp
	$(CPP) $(CPPFLAGS) -c -o $@ $<

clean:
	$(RM) $(OBJS) $(BIN)
