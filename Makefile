all: ArrayOfPointer

ArrayOfPointer: main.o func.o
	gcc main.o func.o -o ArrayOfPointer -lm -ggdb3
main.o: main.c
	gcc -c main.c -o main.o -lm -ggdb3

func.o: func.c
	gcc -c func.c -o func.o -lm -ggdb3