CC=gcc
CFLAGS=-I.
DEPS = bsq.h
OBJ =  error_control.c read_map.c

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

bsq: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o bsq
