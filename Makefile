all: Onegin
 
Onegin: main.o create_array.o print_text.o sorting.o
	gcc main.o create_array.o print_text.o sorting.o -o Onegin -lm -ggdb3  -fsanitize=address
	
main.o: main.c
	gcc -c main.c -o main.o -lm -ggdb3 -fsanitize=address

create_array.o: create_array.c
	gcc -c create_array.c -o create_array.o -lm -ggdb3 -fsanitize=address 

print_text.o: print_text.c
	gcc -c print_text.c -o print_text.o -lm -ggdb3 -fsanitize=address 

sorting.o: sorting.c
	gcc -c sorting.c -o sorting.o -lm -ggdb3 -fsanitize=address 