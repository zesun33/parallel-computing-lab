# Parallel Computing Concepts

> **Learning Goal**: Understand the fundamentals of parallel computing before diving into OpenMP/MPI.

## Why Parallel Computing?

**Moore's Law is slowing down** — we can't just make faster single cores anymore.
**Solution**: Use multiple cores/processors working together.

## Key Terminology

### Thread vs Process

| Aspect | Thread | Process |
|--------|--------|---------|
| Memory | Shared | Separate |
| Creation | Fast | Slow |
| Communication | Direct (shared memory) | Message passing |
| Example | OpenMP | MPI |

### Parallelism Types

1. **Data Parallelism**: Same operation on different data
   ```
   for i in 0..N: C[i] = A[i] + B[i]  // Each i is independent
   ```

2. **Task Parallelism**: Different operations in parallel
   ```
   Thread 1: Load data
   Thread 2: Compute A
   Thread 3: Compute B
   ```

## Shared Memory vs Distributed Memory

### Shared Memory (OpenMP)
```
┌─────────────────────────────────────┐
│           Shared Memory             │
└─────────────────────────────────────┘
      ↑       ↑       ↑       ↑
   Thread0 Thread1 Thread2 Thread3
```
- All threads can access all memory
- Communication via memory reads/writes
- Need synchronization (locks, atomics)
- Limited to single machine

### Distributed Memory (MPI)
```
┌──────────┐   ┌──────────┐   ┌──────────┐
│ Process0 │   │ Process1 │   │ Process2 │
│ Memory   │   │ Memory   │   │ Memory   │
└──────────┘   └──────────┘   └──────────┘
      ↓              ↓              ↓
   ─────────── Network ───────────
```
- Each process has private memory
- Communication via message passing
- Can scale across machines
- More complex programming

## Performance Metrics

### Speedup
```
Speedup(N) = Time(1 thread) / Time(N threads)

Ideal: Speedup(N) = N (linear speedup)
Reality: Speedup(N) < N (due to overhead)
```

### Efficiency
```
Efficiency = Speedup / N

Ideal: 100% (each thread contributes fully)
Good: >70%
Acceptable: >50%
```

### Amdahl's Law

If P = parallel fraction of code:
```
Max Speedup = 1 / (1 - P)

Example: P = 90% → Max Speedup = 10x (no matter how many cores!)
```

**Lesson**: The serial part limits scalability.

## Parallel Overhead

Sources of overhead:
1. **Thread creation/destruction** — Use thread pools
2. **Synchronization** — Minimize locks
3. **False sharing** — Cache line conflicts
4. **Load imbalance** — Uneven work distribution

## TODO: Study Questions

1. [ ] What is Amdahl's Law and what does it tell us?
2. [ ] When would you use OpenMP vs MPI?
3. [ ] What is false sharing?
4. [ ] Why doesn't doubling cores give 2x speedup?

## Next Step

→ Proceed to [01_openmp_basics.md](01_openmp_basics.md)
