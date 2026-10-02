CC=gcc

CFLAGS=-Wall -Wextra -g -I.

CRITERION=$(shell pkg-config --cflags --libs criterion)


SRC=MyBitManipulation.c Myfloat.c MyIntegers.c


.PHONY: all test clean


all: a.out


a.out: main.o $(SRC:.c=.o)
	$(CC) $(CFLAGS) -o $@ $^


test:
	$(CC) $(CFLAGS) tests/*.c $(SRC) $(CRITERION) -o tests_runner
	./tests_runner --verbose


clean:
	rm -f *.o a.out tests_runner
