all: bin/main

bin/main: src/main.c

	gcc -Wall -o bin/main src/main.c