all:
	gcc -o randfile randfile.c

run:
	gcc -o randfile randfile.c
	./randfile

clean:
	rm randfile
	rm *~
