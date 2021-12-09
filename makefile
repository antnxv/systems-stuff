all: caesar.o caesar.h
	gcc -o caesar caesar.o

caesar.o: caesar.c caesar.h
	gcc -c caesar.c

run:
	gcc -c caesar.c
	gcc -o caesar caesar.o
	./caesar

clean:
	rm -f caesar
	rm -f caesar.o
