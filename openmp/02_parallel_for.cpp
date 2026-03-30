/*
 * 02_parallel_for.cpp - Parallelizing Loops with OpenMP
 * 
 * LEARNING GOAL: Understand how to parallelize loops efficiently.
 * 
 * PREREQUISITES:
 * - Complete 01_hello_parallel.cpp
 * - Read notes/01_openmp_basics.md
 * 
 * COMPILE: g++ -fopenmp 02_parallel_for.cpp -o parallel_for
 * RUN:     OMP_NUM_THREADS=4 ./parallel_for
 */

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

#define N 1000000  // Array size

int main() {
    printf("=============================================================\n");
    printf("Parallel For Loop Demo\n");
    printf("=============================================================\n");
    
    // Allocate arrays
    float* A = (float*)malloc(N * sizeof(float));
    float* B = (float*)malloc(N * sizeof(float));
    float* C = (float*)malloc(N * sizeof(float));
    
    // Initialize arrays (serial)
    for (int i = 0; i < N; i++) {
        A[i] = 1.0f;
        B[i] = 2.0f;
    }
    
    // ========================================================================
    // VERSION 1: Serial (baseline)
    // ========================================================================
    double start = omp_get_wtime();
    
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    
    double serial_time = omp_get_wtime() - start;
    printf("Serial time: %.4f seconds\n", serial_time);
    
    // ========================================================================
    // VERSION 2: Parallel For
    // ========================================================================
    // TODO: Uncomment and observe speedup
    
    /*
    start = omp_get_wtime();
    
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
    }
    
    double parallel_time = omp_get_wtime() - start;
    printf("Parallel time: %.4f seconds\n", parallel_time);
    printf("Speedup: %.2fx\n", serial_time / parallel_time);
    */
    
    // ========================================================================
    // VERSION 3: Parallel with Schedule Control
    // ========================================================================
    // TODO: Try different scheduling policies
    
    /*
    // Static: Divide iterations equally upfront
    #pragma omp parallel for schedule(static)
    for (int i = 0; i < N; i++) { C[i] = A[i] + B[i]; }
    
    // Dynamic: Assign chunks at runtime (better for uneven work)
    #pragma omp parallel for schedule(dynamic, 1000)
    for (int i = 0; i < N; i++) { C[i] = A[i] + B[i]; }
    
    // Guided: Start with large chunks, decrease over time
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < N; i++) { C[i] = A[i] + B[i]; }
    */
    
    // ========================================================================
    // VERSION 4: See Which Thread Does What
    // ========================================================================
    // TODO: Uncomment to see work distribution
    
    /*
    int thread_work[16] = {0};  // Count iterations per thread
    
    #pragma omp parallel for
    for (int i = 0; i < 160; i++) {
        int tid = omp_get_thread_num();
        thread_work[tid]++;
    }
    
    printf("\nWork distribution:\n");
    for (int t = 0; t < omp_get_max_threads(); t++) {
        printf("  Thread %d: %d iterations\n", t, thread_work[t]);
    }
    */
    
    printf("\nTODO: Uncomment the sections above one by one!\n");
    
    // Cleanup
    free(A);
    free(B);
    free(C);
    
    return 0;
}

// ============================================================================
// EXERCISES
// ============================================================================
// 1. Why is parallel version faster? (or is it?)
// 2. Try increasing N to 100M. How does speedup change?
// 3. Compare static vs dynamic scheduling. When is each better?
// 4. What happens with 1 thread? (OMP_NUM_THREADS=1)
// ============================================================================
