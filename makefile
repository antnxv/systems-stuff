all:
	gcc -o forkin cforkin.c

run:
	gcc -o forkin cforkin.c
	./forkin

clean:
	rm forkin
