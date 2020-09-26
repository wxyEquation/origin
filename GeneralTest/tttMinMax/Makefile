OBJ = GameTree.o MinMax.o Tic.o interface.o test.o

test: $(OBJ)
	g++ $(OBJ) -o test

test.o: test.cpp
	g++ -c test.cpp

interface.o: interface.cpp
	g++ -c interface.cpp 

Tic.o: Tic.cpp
	g++ -c Tic.cpp

MinMax.o: MinMax.cpp
	g++ -c MinMax.cpp

GameTree.o: GameTree.cpp 
	g++ -c GameTree.cpp


.PHONY: clean
clean: 
	del /Q /S *.o *.h.gch test
