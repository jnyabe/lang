SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
BIN = test

CXXFLAGS = -g -O2 -DNDEBUG
LDFLAGS = 

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $<

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS) $(BIN)

