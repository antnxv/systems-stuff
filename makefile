all: dirinfo.c
	gcc -o dirinfo dirinfo.c

run:
	gcc -o dirinfo dirinfo.c
	./dirinfo

clean:
	rm dirinfo
