all: main.c
	gcc -o argparse main.c

run:
	gcc -o argparse main.c
	./argparse

clean:
	rm argparse
