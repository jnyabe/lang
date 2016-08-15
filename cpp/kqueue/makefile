CC = clang++

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

BIN = test


CCFLAGS = -std=c++11 -g -O2
LDFLAGS = -lreadline


all: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CCFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	$(RM) $(BIN) $(OBJS)


