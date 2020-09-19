PY  = C:/Users/wxy_E/AppData/Local/Programs/Python/Python38

_fibmodule.pyd: fibmodule.o fibmodule_wrap.o
	gcc -shared $^ -o $@ -L$(PY)/libs -lpython38

fibmodule.o: fibmodule.c
	gcc -c -fpic $^ 

fibmodule_wrap.o: fibmodule_wrap.c
	gcc -c -fpic $^ -I$(PY)/include

fibmodule_wrap.c: fibmodule.i
	swig -python fibmodule.i