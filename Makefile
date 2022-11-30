CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs -pthread

OBJECTS = FileParser.o MultiStringLCS.o TwoStringLCS.o


main: main.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) *.o *.gc* *.dSYM test/test core main