SRCS = $(wildcard *.cpp)
DEPS = $(SRCS:.cpp=.d)
OBJS = $(SRCS:.cpp=.o)

TARGET = libcommon.a

CXXFLAGS = -g -O2 -DNDEBUG
LDFLAGS = 

all: $(TARGET)

$(TARGET): $(OBJS) $(DEPS)
	$(AR) -r $(TARGET) $(OBJS)

%.o:%.cpp %.d
	$(CXX) -c $(CXXFLAGS) -o $@ $<

%.d:%.cpp
	$(CXX) -MM $(CXXFLAGS) $< > $@

clean:
	$(RM) $(OBJS) $(DEPS) $(TARGET) 

-include $(DEPS)

