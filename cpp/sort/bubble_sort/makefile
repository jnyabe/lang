SRCS = $(wildcard *.cpp) $(wildcard ../common/*.cpp)
OBJS = $(SRCS:.cpp=.o)

CC = clang++
BIN = bubble_sort
CPPFLAGS = -g -O2 -std=c++11 -I../common
LDFLAGS = 

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CPPFLAGS) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $(CPPFLAGS) $<

clean:
	$(RM) $(OBJS) $(BIN)
