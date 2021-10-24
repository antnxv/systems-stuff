all: main.o list.o
	gcc -o test main.o list.o

main.o: main.c list.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

run:
	make
	./test

clean:
	rm test
	rm *.o
