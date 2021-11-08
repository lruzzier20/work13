all: main.o foo.o
	gcc -o fin main.o foo.o

main.o: main.c foo.h
	gcc -c main.c

foo.o: foo.c foo.h
	gcc -c foo.c

run:
	./fin

clean:
	rm *.o
