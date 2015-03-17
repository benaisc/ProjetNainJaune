CXX=g++
CXXFLAGS=-Wall -ansi -pedantic -std=c++11
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) $^ -o $@

.o: $(SRC)
	$(CXX) $(CXXFLAGS) -c $^


clean:
	rm -rf *.o log.txt score.txt
