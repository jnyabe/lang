all: $(BIN)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)
%.o:%.cpp
	$(CXX) -c $(CXXFLAGS) -o $@ $<

%.o:%.c
	$(CXX) -c $(CXXFLAGS) -o $@ $<


clean:
	$(RM) $(BIN) $(OBJS)

