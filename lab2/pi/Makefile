.SUFFIXES: -omp -omp-i
CC       = gcc

OPENMP	 = -fopenmp
CFLAGS   = -Wall -std=c99 -O3 $(OPENMP) -fno-inline -I.  
CLIBS    = -L. -lm
EINCL    = -I${EXTRAE_HOME}/include/ -I.
ELIBS    = -L$(EXTRAE_HOME)/lib -lomptrace -L/usr/lib -lrt

.c-omp:
	$(CC) -D_DEBUG_ $< $(CFLAGS) -o $@ $(CLIBS) 

.c-omp-i:
	$(CC) $< $(CFLAGS) $(EINCL) -o $@ $(CLIBS) $(ELIBS)

clean:
	rm -f *-omp *-omp-i *.prv *.row *.pcf
