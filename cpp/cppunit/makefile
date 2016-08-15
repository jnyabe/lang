SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

BIN = sample_test

CC = g++
CCFLAGS = -I/usr/local/include -O2 -g
LDFLAGS = -L/usr/local/lib -lcppunit

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $(CCFLAGS) $< 

clean:
	$(RM) $(BIN) $(OBJS)
