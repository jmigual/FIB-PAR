#!/bin/csh
# following option makes sure the job will run in the current directory
#$ -cwd
# following option makes sure the job has the same environmnent variables as the submission shell
#$ -V

setenv PROG pi_omp_overhead
make $PROG

./$PROG 1 > pi_omp_overhead_times.txt
