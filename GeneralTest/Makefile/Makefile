final: final.o source1.o source2.o
	g++ final.o source1.o source2.o -o final.exe

final.o: final.cpp
	g++ -c final.cpp

source1.o: source1.cpp
	g++ -c source1.cpp

source2.o: source2.c
	gcc -c source2.c

.PHONY: clean
clean: 
	del /Q /S *.o *.h.gch final