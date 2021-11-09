all: cstructrw.c
	gcc -o structrw cstructrw.c

clean:
	rm structrw
