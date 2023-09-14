all: Onegin
 
Onegin: main.o func.o
	gcc main.o func.o -o Onegin -lm -ggdb3  -fsanitize=address
main.o: main.c
	gcc -c main.c -o main.o -lm -ggdb3 -fsanitize=address

func.o: func.c
	gcc -c func.c -o func.o -lm -ggdb3 -fsanitize=address 