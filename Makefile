default: main

logf.o: src/logf.c
	gcc -Wall -Werror -c -fpic src/logf.c

liblogf.so: logf.o
	gcc -shared -fpic -o liblogf.so logf.o

main: liblogf.so test/main.c
	gcc -L. -llogf -o main -Isrc/ test/main.c

clean:
	rm -f liblogf.so logf.o main

.PHONY: clean
