# Parallel Computing Lab

CPU parallel programming with OpenMP and MPI.

## Goals

This repo covers:
- Parallel programming concepts (threads, processes, synchronization)
- OpenMP for shared-memory parallelism
- MPI for distributed-memory parallelism (future)
- Parallel patterns: reduction, prefix sum, map
- Performance analysis: speedup, efficiency, scaling

## 📚 Learning Roadmap

### Phase 1: Theory (Notes)

| # | Note | Topic | Status |
|---|------|-------|--------|
| 0 | [00_parallel_concepts.md](notes/00_parallel_concepts.md) | Parallelism fundamentals | ⬜ |
| 1 | [01_openmp_basics.md](notes/01_openmp_basics.md) | OpenMP syntax and directives | ⬜ |
| 2 | [02_parallel_patterns.md](notes/02_parallel_patterns.md) | Map, reduce, scan patterns | ⬜ |
| 3 | [03_performance_analysis.md](notes/03_performance_analysis.md) | Amdahl's law, scaling | ⬜ |
| 4 | [04_mpi_basics.md](notes/04_mpi_basics.md) | MPI concepts (future) | ⬜ |

### Phase 2: OpenMP Implementation

| # | File | Concept | Prereq Notes | Status |
|---|------|---------|--------------|--------|
| 1 | [01_hello_parallel.cpp](openmp/01_hello_parallel.cpp) | Basic parallel region | 0, 1 | ⬜ |
| 2 | [02_parallel_for.cpp](openmp/02_parallel_for.cpp) | Parallel loops | 1 | ⬜ |
| 3 | [03_reduction.cpp](openmp/03_reduction.cpp) | Reduction patterns | 1, 2 | ⬜ |
| 4 | [04_critical_atomic.cpp](openmp/04_critical_atomic.cpp) | Synchronization | 1 | ⬜ |
| 5 | [05_gemm_openmp.cpp](openmp/05_gemm_openmp.cpp) | Parallel GEMM | 1, 2, 3 | ⬜ |

### Phase 3: MPI Implementation (Future)

| # | File | Concept | Status |
|---|------|---------|--------|
| 1 | [01_hello_mpi.cpp](mpi/01_hello_mpi.cpp) | MPI basics | ⬜ |
| 2 | [02_point_to_point.cpp](mpi/02_point_to_point.cpp) | Send/Receive | ⬜ |
| 3 | [03_collective.cpp](mpi/03_collective.cpp) | Broadcast, Reduce | ⬜ |
| 4 | [04_gemm_mpi.cpp](mpi/04_gemm_mpi.cpp) | Distributed GEMM | ⬜ |

## 🔧 Build & Run

```bash
# Build OpenMP examples
make openmp

# Run with different thread counts
OMP_NUM_THREADS=1 ./bin/05_gemm_openmp   # Serial baseline
OMP_NUM_THREADS=4 ./bin/05_gemm_openmp   # 4 threads
OMP_NUM_THREADS=8 ./bin/05_gemm_openmp   # 8 threads
```

## ⚠️ Prerequisites

**OpenMP**: Included with GCC (you have it ✅)
```bash
g++ -fopenmp program.cpp -o program
```

**MPI**: Install when ready (not required initially)
```bash
# Windows: MS-MPI or Intel MPI
# Linux: sudo apt install mpich
```

## 🔗 Relevance

**Micron Interview**: Covers OpenMP/MPI from preferred qualifications. Understanding parallel computing is essential for memory systems pathfinding.

## 📖 References

- OpenMP 5.0 Specification
- "Parallel Programming in C with MPI and OpenMP" - Quinn
- Lawrence Livermore OpenMP Tutorial
