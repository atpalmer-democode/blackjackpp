P=bj
OBJECTS=bj.o card.o
CC=g++

$P: $(OBJECTS)

.PHONY: clean
clean:
	rm $(OBJECTS) $(P)
