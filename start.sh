#/!/bin/bash

size=1

#src=./texts2/*

if [ -n "$size" ]; then
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c 
else
	read size
	gcc -Wall -Wextra -o main -D BUFFER_SIZE=$size get_next_line.c get_next_line_utils.c gnl_main.c
fi
./main
