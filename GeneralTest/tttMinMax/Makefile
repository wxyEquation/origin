test: test.o Tic.o
	gcc test.o Tic.o -o test

test.o: test.c
	gcc -c test.c

Tic.o: Tic.c Tic.h
	gcc -c Tic.c Tic.h

.PHONY: clean
clean: 
	del /Q /S *.o *.h.gch test
