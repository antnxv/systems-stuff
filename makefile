all: inter.o worker.o caesar.h
	gcc -o interface inter.o
	gcc -o worker worker.o

inter.o: inter.c caesar.h
	gcc -c inter.c

worker.o: worker.c caesar.h
	gcc -c worker.c

clean:
	rm -f interface
	rm -f worker
	rm -f *.o
	rm -f i2w
	rm -f w2i
