all: control.o control.h
	gcc -o control control.o

control.o: control.c control.h
	gcc -c control.c

run:
	gcc -c control.c
	gcc -o control control.o

clean:
	rm control
	rm -rf *.o
