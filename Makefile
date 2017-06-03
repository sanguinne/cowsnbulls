CFLAGS = -Wall -Werror
.PHONY: clean all cowsbulls test

all :
	make bin/cowsbulls

bin/cowsbulls : build/main.o build/usersnumber.o
	gcc build/main.o build/usersnumber.o -o bin/cowsbulls $(CFLAGS)

build/main.o : src/main.c src/usersnumber.h
	gcc -c src/main.c -o build/main.o $(CFLAGS)

build/usersnumber.o : src/usersnumber.c src/usersnumber.h
	gcc -c src/usersnumber.c -o build/usersnumber.o $(CFLAGS)

test:
	make bin/cowsbulls-test

bin/cowsbulls-test : build/test/main.o build/test/test.o build/test/usersnumber.o
	gcc build/test/main.o build/test/test.o build/test/usersnumber.o -o bin/cowsbulls-test $(CFLAGS)

build/test/main.o : test/main.c thirdparty/ctest.h
	gcc -I thirdparty -c test/main.c -o build/test/main.o $(CFLAGS)

build/test/test.o : test/test.c thirdparty/ctest.h
	gcc -c -I thirdparty test/test.c -o build/test/test.o $(CFLAGS)

build/test/usersnumber.o : src/usersnumber.c src/usersnumber.h
	gcc -c src/usersnumber.c -o build/test/usersnumber.o $(CFLAGS)

clean :
	rm -rf build/*.o build/test/*.o
	rm -f bin/cowsbulls bin/cowsbulls-test