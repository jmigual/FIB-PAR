CC = gcc

OPENMP	 = -fopenmp
CFLAGS   = -Wall -O0 -std=c99 -march=native $(OPENMP)
CLIBS    = 
IINCL    = -I${EXTRAE_HOME}/include/ -I/usr/include/
ILIBS    = -L$(EXTRAE_HOME)/lib -lomptrace -L/usr/lib -lrt

TARGETS  = pi_seq pi_omp_overhead pi_omp pi_omp_critical pi_omp_lock pi_omp_atomic pi_omp_sumvector pi_omp_padding pi_omp_i pi_omp_critical_i pi_omp_lock_i pi_omp_atomic_i pi_omp_sumvector_i pi_omp_padding_i
all: $(TARGETS) 

pi_seq: pi_seq.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_overhead: pi_omp_overhead.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp: pi_omp.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_critical: pi_omp_critical.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_lock: pi_omp_lock.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_atomic: pi_omp_atomic.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS)

pi_omp_sumvector: pi_omp_sumvector.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_padding: pi_omp_padding.c
	$(CC) $(CFLAGS) $< -o $@ $(CLIBS) 

pi_omp_i: pi_omp.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

pi_omp_critical_i: pi_omp_critical.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

pi_omp_lock_i: pi_omp_lock.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

pi_omp_atomic_i: pi_omp_atomic.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

pi_omp_sumvector_i: pi_omp_sumvector.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

pi_omp_padding_i: pi_omp_padding.c
	$(CC) -D_EXTRAE_ $(CFLAGS) $(IINCL) $< -o $@ $(CLIBS) $(ILIBS)

clean:
	rm -rf $(TARGETS)

ultraclean:
	rm -rf $(TARGETS) TRACE*.mpit *.prv *.pcf *.row set-0 *.mpits *.o* *.e* *.txt *.ps *.pdf
