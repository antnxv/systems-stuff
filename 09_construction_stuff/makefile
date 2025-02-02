all: main.o structy.o
	gcc -o structy main.o structy.o

main.o: main.c structy.h
	gcc -c main.c

structy.o: structy.c structy.h
	gcc -c structy.c

run:
	make
	./structy

clean:
	rm *.o
	rm structy
