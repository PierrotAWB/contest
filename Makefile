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
	touch input.in output.out
	./main < input.in > output.out

run :
	touch input.in output.out
	./main < input.in > output.out

.PHONY: all main clean dist
