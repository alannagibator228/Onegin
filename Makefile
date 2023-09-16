all: Onegin
 
Onegin: main.o create_array.o print_text.o sorting.o
	g++ main.o create_array.o print_text.o sorting.o -o Onegin -lm -ggdb3  -fsanitize=address
	
main.o: main.cpp
	g++ -c main.cpp -o main.o -lm -ggdb3 -fsanitize=address

create_array.o: create_array.cpp
	g++ -c create_array.cpp -o create_array.o -lm -ggdb3 -fsanitize=address 

print_text.o: print_text.cpp
	g++ -c print_text.cpp -o print_text.o -lm -ggdb3 -fsanitize=address 

sorting.o: sorting.cpp
	g++ -c sorting.cpp -o sorting.o -lm -ggdb3 -fsanitize=address 