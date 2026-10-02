# CSE 220 — Homework 3

C implementations of bit manipulation, IEEE-754 floating-point construction,
and integer representation conversion.

## Files

- `BitManipulation/`: bit manipulation functions and header.
- `Myfloat/`: floating-point functions and header.
- `MyIntegers/`: integer representation conversion and header.
- `tests/`: Criterion tests.
- `main.c`: example driver.
- `README.txt`: detailed assignment write-up.

## Build the example program

With CMake 4.0 or newer and a C compiler:

```sh
cmake -S . -B build
cmake --build build
```

## Run the tests

With GCC, pkg-config, and Criterion installed:

```sh
gcc -Wall -Wextra -g -IBitManipulation -IMyfloat -IMyIntegers tests/*.c BitManipulation/MyBitManipulation.c Myfloat/Myfloat.c MyIntegers/MyIntegers.c $(pkg-config --cflags --libs criterion) -o tests_runner
./tests_runner --verbose
```

The supplied Makefile uses a flat source layout. The command above uses the
current directory layout.
