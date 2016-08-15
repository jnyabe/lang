CXX = clang++
CXXFLAGS = -std=c++11 -stdlib=libc++
LDFLAGS =
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)

BIN = test_list

all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDFLAGS)

%.o:%.cpp
	$(CXX) -c -o $@ $(CXXFLAGS)  $< 
