P=bj
OBJECTS=bj.o card.o shoe.o hand.o
CXXFLAGS=-O0 -g -Wall -Wextra -pedantic
CXX=g++

$P: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $P $(OBJECTS)

.PHONY: clean
clean:
	rm $(OBJECTS) $(P)
