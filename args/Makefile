all: args.o booleanargs.o valueargs.o
	cp -f ./args.o ../args.o
	cp -f ./booleanargs.o ../booleanargs.o
	cp -f ./valueargs.o ../valueargs.o
	rm -f *.o

args.o: args.cpp
	gcc -c -o args.o args.cpp
	
valueargs.o: valueargs.cpp
	gcc -c -o valueargs.o valueargs.cpp

booleanargs.o: booleanargs.cpp
	gcc -c -o booleanargs.o booleanargs.cpp

clean:
	rm -f *.o