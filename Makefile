CC=clang
CFLAGS= -g -Wall -O2 -Wpedantic -Wextra

all: quicksort heapsort

quicksort: build
	$(CC) quicksort.c -o build/quicksort $(CFLAGS)

heapsort: build
	$(CC) heapsort.c -o build/heapsort $(CFLAGS)

build:
	mkdir build

clean:
	rm -rf build
