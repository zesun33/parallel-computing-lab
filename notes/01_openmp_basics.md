# OpenMP Basics

> **Learning Goal**: Learn the core OpenMP directives and how to parallelize code.

## What is OpenMP?

**Open Multi-Processing** — A pragma-based API for shared-memory parallelism.

**Key advantages**:
- Easy to add to existing code (just add pragmas)
- Compiler handles thread management
- Portable across platforms

## Basic Syntax

```cpp
#include <omp.h>

int main() {
    #pragma omp parallel
    {
        // This code runs on ALL threads
        int tid = omp_get_thread_num();
        printf("Hello from thread %d\n", tid);
    }
    return 0;
}
```

**Compile**: `g++ -fopenmp program.cpp -o program`

## Essential Directives

### 1. `#pragma omp parallel`
Creates a team of threads:
```cpp
#pragma omp parallel
{
    // Code here runs on each thread
}
// Implicit barrier: all threads sync here
```

### 2. `#pragma omp for`
Distributes loop iterations:
```cpp
#pragma omp parallel for
for (int i = 0; i < N; i++) {
    C[i] = A[i] + B[i];  // Each iteration assigned to one thread
}
```

### 3. `#pragma omp parallel for reduction`
Combines results from all threads:
```cpp
double sum = 0.0;
#pragma omp parallel for reduction(+:sum)
for (int i = 0; i < N; i++) {
    sum += A[i];  // Each thread has private sum, combined at end
}
```

### 4. `#pragma omp critical`
Only one thread at a time:
```cpp
#pragma omp parallel for
for (int i = 0; i < N; i++) {
    #pragma omp critical
    {
        shared_counter++;  // Protected from race conditions
    }
}
```

## Key Functions

```cpp
omp_get_num_threads()   // Total threads in current region
omp_get_thread_num()    // Current thread ID (0 to num_threads-1)
omp_set_num_threads(n)  // Set thread count
omp_get_wtime()         // Wall clock time (for benchmarking)
```

## Variable Scoping

| Clause | Meaning |
|--------|---------|
| `shared(x)` | All threads share same variable |
| `private(x)` | Each thread has its own copy (uninitialized) |
| `firstprivate(x)` | Private, initialized with original value |
| `reduction(+:x)` | Private copies combined at end |

## Common Patterns

### Matrix Initialization
```cpp
#pragma omp parallel for
for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
        A[i][j] = 0.0;
    }
}
```

### GEMM (Outer loop parallelization)
```cpp
#pragma omp parallel for
for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        float sum = 0.0f;
        for (int k = 0; k < K; k++) {
            sum += A[i*K + k] * B[k*N + j];
        }
        C[i*N + j] = sum;
    }
}
```

## TODO: Study Questions

1. [ ] What does `#pragma omp parallel for` do?
2. [ ] When should you use `reduction` vs `critical`?
3. [ ] What is the default variable scoping in OpenMP?
4. [ ] How do you control the number of threads?

## TODO: Hands-On Exercise

Try the following in order:
1. [01_hello_parallel.cpp](../openmp/01_hello_parallel.cpp)
2. [02_parallel_for.cpp](../openmp/02_parallel_for.cpp)
3. [03_reduction.cpp](../openmp/03_reduction.cpp)

## Next Step

→ Proceed to [02_parallel_patterns.md](02_parallel_patterns.md)
