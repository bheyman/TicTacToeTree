CC=gcc
CFLAGS=-I./include
DEPS=utils.h
OBJ=src/main.o src/utils.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

MakeTree: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f MakeTree src/*.o
