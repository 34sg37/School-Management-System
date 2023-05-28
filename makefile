CXX=g++
CXXFLAGS=-std=c++11 -Wall

SRCS=main.cpp SchoolManagerSystem.cpp Course.cpp Student.cpp
OBJS=$(subst .cpp,.o,$(SRCS))
EXECUTABLE=SchoolManagerSystem

all: $(EXECUTABLE)
	./$(EXECUTABLE)

$(EXECUTABLE): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@

run: $(EXECUTABLE)
	./$(EXECUTABLE)

clean:
	rm -f $(OBJS) $(EXECUTABLE)