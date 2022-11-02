CC = g++
FLAGS = -Wall

SRC = main.cpp
OBJ = ${SRC:.c=.o}

all : main run

main : main.cpp
	${CC} ${FLAGS} -o $@ $^

clean :
	rm -f main

test :
	./main < input.in > output.out

run :
	./main < input.in > output.out

.PHONY: all main clean dist test run
