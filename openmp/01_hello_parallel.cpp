/*
 * 01_hello_parallel.cpp - First OpenMP Program
 * 
 * LEARNING GOAL: Understand how OpenMP creates parallel regions.
 * 
 * PREREQUISITES:
 * - Read notes/00_parallel_concepts.md
 * - Read notes/01_openmp_basics.md
 * 
 * COMPILE: g++ -fopenmp 01_hello_parallel.cpp -o hello_parallel
 * RUN:     ./hello_parallel
 *          OMP_NUM_THREADS=4 ./hello_parallel
 */

#include <omp.h>
#include <stdio.h>

int main() {
    printf("=============================================================\n");
    printf("OpenMP Hello World\n");
    printf("=============================================================\n");
    
    // Before parallel region - single thread
    printf("Before parallel region: Thread 0 (only thread)\n");
    
    // ========================================================================
    // STEP 1: Basic Parallel Region
    // ========================================================================
    // TODO: Uncomment and observe behavior
    
    /*
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        int num_threads = omp_get_num_threads();
        printf("Hello from thread %d of %d\n", tid, num_threads);
    }
    */
    
    // ========================================================================
    // STEP 2: Control Number of Threads
    // ========================================================================
    // TODO: Try setting number of threads programmatically
    
    /*
    omp_set_num_threads(4);
    
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        printf("Thread %d reporting\n", tid);
    }
    */
    
    // ========================================================================
    // STEP 3: Thread-Specific Work
    // ========================================================================
    // TODO: Each thread does different work based on ID
    
    /*
    #pragma omp parallel
    {
        int tid = omp_get_thread_num();
        
        if (tid == 0) {
            printf("Master thread (ID=0) does special work\n");
        } else {
            printf("Worker thread %d does regular work\n", tid);
        }
    }
    */
    
    printf("\nTODO: Uncomment the sections above one by one!\n");
    printf("After parallel region: Back to single thread\n");
    
    return 0;
}

// ============================================================================
// EXERCISES
// ============================================================================
// 1. Run with different OMP_NUM_THREADS values. What happens?
// 2. What is the default number of threads?
// 3. Notice the order of "Hello" messages - is it deterministic?
// 4. What happens if you remove #pragma omp parallel?
// ============================================================================
