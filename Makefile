compiler = gcc -g
cflags = -std=c99 -lm  -llapack -lblas

headers = $(wildcard *.h)
sources = $(wildcard *.c)
objects = $(sources:.c=.o)

executables: main

%.o: %.c $(headers)
	$(compiler) -c -o $@ $< $(cflags)

arnoldi: $(objects)
	$(compiler) -o $@ $^ $(cflags)

main: $(objects)
	$(compiler) -o $@ $^ $(cflags)
clean:
	rm -f main 

mrproper: clean
