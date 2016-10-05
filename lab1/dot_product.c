void dot_product (long N, double A[N], double B[N], double *acc){    
double prod;
    int i;
    *acc=0.0;
    for (i=0; i<N; i++) {
        // Start TAREADOR task
    	tareador_start_task("my_func");	
        prod = my_func(A[i], B[i]);
        *acc += prod;
        // End TAREADOR task
        tareador_end_task("my_func");
    }
}

int main(int argc, char **argv) {
    struct timeval start;
    struct timeval stop;
    unsigned long elapsed;
    double result;

    double *B = malloc(size*sizeof(double));

    tareador_ON ();

    int i;

    // Start TAREADOR task
    tareador_start_task("init_A");
    for (i=0; i< size; i++) A[i]=i;
    // End TAREADOR task
    tareador_end_task("init_A");
    
    // Start TAREADOR task
    tareador_start_task("init_B");
    for (i=0; i< size; i++) B[i]=2*i;
    // End TAREADOR task    
    tareador_end_task("init_B");

    gettimeofday(&start,NULL);

    // Disable TAREADOR object
    tareador_disable_object(&result);

    // Start TAREADOR task
    tareador_start_task("dot_product");    
    dot_product (size, A, B, &result);
    // End TAREADOR task
    tareador_end_task("dot_product");

    // Enable TAREADOR object again
    tareador_enable_object(&result);

    tareador_OFF ();

    gettimeofday(&stop,NULL);
    elapsed = 1000000 * (stop.tv_sec - start.tv_sec);
    elapsed += stop.tv_usec - start.tv_usec;
    printf("Result of Dot product i= %le\n", result);
    printf("Execution time (us): %lu \n", elapsed);

    return 0;
}