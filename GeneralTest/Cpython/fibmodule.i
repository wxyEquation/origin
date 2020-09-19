%module fibmodule

%{
	extern double fib(int n);	
	extern double foo();
%}

extern double fib(int n);
extern double foo();