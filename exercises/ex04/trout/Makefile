util.o: util.c util.h
	cc -c util.c

trout.o: trout.c trout.h
	gcc -c trout.c

main.o: main.c trout.o util.o
	gcc -c main.c

trout: main.o
	gcc main.o trout.o util.o -o trout