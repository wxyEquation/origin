.PHONY: all
all: MinMax.o GameTree.o

MinMax.o: MinMax.cpp
	g++ -c MinMax.cpp

GameTree.o: GameTree.cpp
	g++ -c GameTree.cpp

.PHONY: clean
clean: 
	del /Q /S *.o *.h.gch test
