#!/bin/csh
# following option makes sure the job will run in the current directory
#$ -cwd
# following option makes sure the job has the same environmnent variables as the submission shell
#$ -V

setenv size 100000000
#setenv PROG pi_omp
setenv PROG pi_omp_critical
#setenv PROG pi_omp_lock
#setenv PROG pi_omp_atomic
#setenv PROG pi_omp_sumvector
#setenv PROG pi_omp_padding
#setenv OMP_NUM_THREADS 1
setenv OMP_NUM_THREADS 8

/usr/bin/time -o ${PROG}_time.txt ./$PROG $size
