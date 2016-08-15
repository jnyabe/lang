SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

CC = clang++
BIN = fizzbuzz
CPPFLAGS = -g -O2 -std=c++11
LDFLAGS = 

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $(CPPFLAGS) $<

clean:
	$(RM) $(OBJS) $(BIN)
