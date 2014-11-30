CC=clang
CFLAGS= -g -Wall -O2 -Wpedantic -Wextra

all: quicksort heapsort bloomfilter

quicksort: build
	$(CC) quicksort.c -o build/quicksort $(CFLAGS)

heapsort: build
	$(CC) lucyheapsort.c -o build/lucyheapsort $(CFLAGS)

bloomfilter: build
	curl http://www.gutenberg.org/cache/epub/2265/pg2265.txt > hamlet.txt
	python hamlet.py
	$(CC) bloomfilter.c -o build/bloomfilter $(CFLAGS)

build:
	mkdir build

clean:
	rm -rf build
