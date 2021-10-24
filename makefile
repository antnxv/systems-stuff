all: main.o list.o librayray.o
	gcc -o playlist main.o list.o librayray.o

main.o: main.c list.h librayray.h
	gcc -c main.c

list.o: list.c list.h
	gcc -c list.c

librayray.o: librayray.c librayray.h
	gcc -c librayray.c

run:
	make
	./playlist

clean:
	rm playlist
	rm *.o
