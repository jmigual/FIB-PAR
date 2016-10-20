/*
 * Compute pi by approximating the area under the curve f(x) = 4 / (1 + x*x)
 * between 0 and 1.
 *
 * Parallel version using OpenMP
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <omp.h>	/* OpenMP */

#if _EXTRAE_
#include "extrae_user_events.h"
// Extrae Constants
#define  PROGRAM    1000
#define  END        0
#define  SERIAL     1
#define  PARALLEL   2
#else 
double getusec_() {
        struct timeval time;
        gettimeofday(&time, NULL);
        return ((double)time.tv_sec * (double)1e6 + (double)time.tv_usec);
}

#define START_COUNT_TIME stamp = getusec_();
#define STOP_COUNT_TIME(_m) stamp = getusec_() - stamp;\
                        stamp = stamp/1e6;\
                        printf ("%s: %0.6fs\n",(_m), stamp);
#endif

#if _EXTRAE_
#define NUMITERS 4
#define NTHREADS 12 
#else
#define NUMITERS 10000
#define NTHREADS 24 
#endif

int main(int argc, char *argv[]) {
#if _EXTRAE_
    Extrae_event (PROGRAM, SERIAL);
#else
    double stamp;
    START_COUNT_TIME;
#endif

    double x, sum=0.0, pi=0.0;
    double step;

    const char Usage[] = "Usage: pi <num_steps> (try 1000000000)\n";
    if (argc < 2) {
	fprintf(stderr, Usage);
	exit(1);
    }
    long int num_steps = atoi(argv[1]);
    step = 1.0/(double) num_steps;

#if _EXTRAE_
    Extrae_event (PROGRAM, END);
#endif

    /* do computation -- using all available threads */
#if _EXTRAE_
    Extrae_event (PROGRAM, PARALLEL);
#else
    printf("All overheads expressed in microseconds\n");
    printf("Nthr\tTime\tTime per thread\n");
#endif
    
    for (int n_threads=2; n_threads<=NTHREADS; n_threads++) {
	omp_set_num_threads(n_threads);
#if _EXTRAE_
#else
	double stamp=getusec_();
#endif
        for (int iter=0; iter<NUMITERS ; iter++) {
            sum = 0.0;
            #pragma omp parallel private(x, sum) 
            {
                for (long int i=0; i<num_steps; ++i) {
                    x = (i+0.5)*step;
                    sum += 4.0/(1.0+x*x);
                }
            }
        }
#if _EXTRAE_
#else
    	stamp=getusec_()-stamp;
    	printf("%d\t%.4f\t%.4f\n", n_threads, stamp/NUMITERS, stamp/(NUMITERS*n_threads));
#endif
    }
#if _EXTRAE_
    Extrae_event (PROGRAM, END);
    Extrae_event (PROGRAM, SERIAL);
#endif
    pi = step * sum / NTHREADS;

    /* print results */
    printf("Number pi after %ld iterations = %.15f\n", num_steps, pi);

#if _EXTRAE_
    Extrae_event (PROGRAM, END);
#else
    STOP_COUNT_TIME("Total execution time");
#endif

    return EXIT_SUCCESS;
}
