SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
CXXFLAGS = -g -O2

bin = test

all: $(bin)

$(bin): $(OBJS) 
	$(CXX) -o $@ $?

%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@  $<
