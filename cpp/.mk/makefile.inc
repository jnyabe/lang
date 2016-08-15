all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
%.cpp:%.o
	$(CXX) -c $(CXXFLAGS) -o $@ $<

%.c:%.o
	$(CXX) -c $(CXXFLAGS) -o $@ $<


clean:
	$(RM) $(BIN) $(OBJS)

