all: control.o write.o control.h 
	gcc -o control control.o
	gcc -o write write.o

control.o: control.c control.h
	gcc -c control.c

write.o: write.c control.h
	gcc -c write.c

run:
	gcc -c control.c
	gcc -c write.c
	gcc -o control control.o
	gcc -o write write.o

clean:
	rm -f log.txt
	rm -f control
	rm -f write
	rm -f *.o
