CC       = gcc

OPENMP   = -fopenmp
CFLAGS   = -Wall -O3 -fno-inline $(OPENMP)

TARGET  = 1.serial 2.parallel

program: $(TARGET)

1.serial: 1.serial.c
	$(CC) $< $(CFLAGS) -o $@ 

2.parallel: 2.parallel.c
	$(CC) $< $(CFLAGS) -fopenmp -o $@ 

clean:
	rm -f $(TARGET)
