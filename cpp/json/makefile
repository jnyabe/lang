SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

BIN = jsonarray-test

CC = g++
CXXFLAGS = -I/usr/local/include/jsoncpp
LDFLAGS = -L/usr/local/lib -ljsoncpp

all: $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CC) -c -o $@ $(CXXFLAGS) $< 

clean:
	$(RM) $(BIN) $(OBJS)
