all: main.o foo.o
	gcc -o a.out main.o foo.o

main.o: main.c foo.h
	gcc -c main.c

foo.o: foo.c foo.h
	gcc -c foo.c

run:
	./a.out

clean:
	rm *.o

read_data:
	./a.out -read_data

read_csv:
	./a.out -read_csv

add_data:
	./a.out add_data

update_data:
	./a.out update_data
