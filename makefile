all: funk.c
	gcc funk.c

run:
	gcc funk.c
	./a.out

clear:
	rm ./a.out
