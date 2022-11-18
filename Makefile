all: wexport wimport
	rm -f *.o

args.o :
	g++ -c -o args.o ./args/args.cpp

strex.h : 
	ln -sf ./strex/strex.h ./strex.h

strex.o :
	g++ -c -o strex.o ./strex/strex.cpp

wtl.o : wtl.cpp strex.h
	g++ -c -o wtl.o wtl.cpp

wtl.out : wtl.o strex.o strex.h args.o
	g++ -o wtl.out wtl.o strex.o args.o

wexport : wexport.cpp strex.h wtl.o strex.o args.o booleanargs.o valueargs.o
	g++ -c -o wexport.o wexport.cpp
	g++ -o wexport wexport.o strex.o wtl.o args.o booleanargs.o valueargs.o

wimport :wimport.cpp strex.h wtl.o strex.o args.o booleanargs.o valueargs.o
	g++ -c -o wimport.o wimport.cpp
	g++ -o wimport wimport.o strex.o wtl.o args.o booleanargs.o valueargs.o

clean :
	rm -f *.o