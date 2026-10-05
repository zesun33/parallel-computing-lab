# Parallel Computing Lab

<!-- BEGIN GENERATED PROJECT GUIDE -->

## Purpose and first steps

Learn CPU parallelism by completing OpenMP exercises.

**Who it is for:** Learners moving from serial CPU code to OpenMP parallel regions and loops.

**First task:** Read the OpenMP notes and uncomment the first exercise one section at a time.

**What to expect:** Thread output and loop-timing experiments after completing the marked sections.

**Current scope:** Two OpenMP exercises with commented-out parallel sections. Reductions, synchronization, MPI, and measured scaling studies are future work.

**Start here:** [OpenMP basics](notes/01_openmp_basics.md).

**Related projects:** [cuda-gemm-optimization](https://github.com/zesun33/cuda-gemm-optimization), [rust-systems-track](https://github.com/zesun33/personal-projects/tree/main/rust-systems-track).

[Choose another project](https://github.com/zesun33/personal-projects/blob/main/GETTING_STARTED.md).
<!-- END GENERATED PROJECT GUIDE -->

CPU parallel programming with OpenMP and MPI.

## Goals

This repo covers:
- Parallel programming concepts (threads, processes, synchronization)
- OpenMP for shared-memory parallelism
- MPI for distributed-memory parallelism (future)
- Parallel patterns: reduction, prefix sum, map
- Performance analysis: speedup, efficiency, scaling

## Learning Roadmap

### Phase 1: Theory (Notes)

| # | Note | Topic | Status |
|---|------|-------|--------|
| 0 | [00_parallel_concepts.md](notes/00_parallel_concepts.md) | Parallelism fundamentals | done |
| 1 | [01_openmp_basics.md](notes/01_openmp_basics.md) | OpenMP syntax and directives | done |
| 2 | `notes/02_parallel_patterns.md` | Map, reduce, scan patterns | planned |
| 3 | `notes/03_performance_analysis.md` | Amdahl's law, scaling | planned |
| 4 | `notes/04_mpi_basics.md` | MPI concepts | planned |

### Phase 2: OpenMP Implementation

| # | File | Concept | Prereq Notes | Status |
|---|------|---------|--------------|--------|
| 1 | [01_hello_parallel.cpp](openmp/01_hello_parallel.cpp) | Basic parallel region | 0, 1 | exercise |
| 2 | [02_parallel_for.cpp](openmp/02_parallel_for.cpp) | Parallel loops | 1 | exercise |
| 3 | `openmp/03_reduction.cpp` | Reduction patterns | 1, 2 | planned |
| 4 | `openmp/04_critical_atomic.cpp` | Synchronization | 1 | planned |
| 5 | `openmp/05_gemm_openmp.cpp` | Parallel GEMM | 1, 2, 3 | planned |

### Phase 3: MPI Implementation (Future)

| # | File | Concept | Status |
|---|------|---------|--------|
| 1 | `mpi/01_hello_mpi.cpp` | MPI basics | planned |
| 2 | `mpi/02_point_to_point.cpp` | Send/Receive | planned |
| 3 | `mpi/03_collective.cpp` | Broadcast, Reduce | planned |
| 4 | `mpi/04_gemm_mpi.cpp` | Distributed GEMM | planned |

## Build & Run

The source files contain exercises: their parallel regions/loops are commented out. Initially the programs print serial output and TODO guidance. Uncomment one section, rebuild, and then compare thread counts; the current files do not establish a measured parallel speedup.

```bash
# Build available OpenMP examples
make openmp

# Run with different thread counts
OMP_NUM_THREADS=1 ./bin/omp_01_hello_parallel
OMP_NUM_THREADS=4 ./bin/omp_02_parallel_for
```

## Prerequisites

**OpenMP** (included with GCC):
```bash
g++ -fopenmp program.cpp -o program
```

**MPI** (optional, for Phase 3):
```bash
# Linux: sudo apt install mpich
```

## References

- OpenMP 5.0 Specification
- "Parallel Programming in C with MPI and OpenMP" — Quinn
- Lawrence Livermore OpenMP Tutorial
