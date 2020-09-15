#
# Makefile
#

all : main.c heap.o employee.h
	gcc -Wall main.c heap.o employee.h

heap.o : heap.h heap.c
	gcc -Wall -c heap.c 

clean: 
	rm -f a.out *.o 