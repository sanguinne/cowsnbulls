all: bin/main

bin/main: src/main.c src/usersnumber.c

	gcc -Wall -o bin/main src/main.c src/usersnumber.c