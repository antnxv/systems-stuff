all:
	gcc -o list list.c

run:
	make
	./list

clean:
	rm list.o
	rm list
