P=bj
OBJECTS=bj.o card.o shoe.o hand.o
CC=g++

$P: $(OBJECTS)

.PHONY: clean
clean:
	rm $(OBJECTS) $(P)
