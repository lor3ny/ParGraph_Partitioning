# ParGraph_Partitioning
Distributed implementation of a multilevel k-way graph partitioning algorithm.

### Path of the project

1. Understanding and comprehension of multilevel k-way algorithm.
  - Coarsening phase
  - Partitioning phase
  - Uncoarsing and refining phase
2. Basic sequential implementation without a refining heuristic, try to understand which rule to follow during coarsening phase
3. Basic sequential implementation with a refining heuristic, try to understand which rule to follow during uncoarsening phase
4. Benchmarking and understanding of parallel optimizations in a distributed fashion (MPI implementation)
5. Parallelization of the different phases one-by-one, using MPI and OpenMP

# Requirements

**g++-12**
```
sudo apt install build-essential
```

**MPI**: Follow install tutorials on the site of the distro chosen

# Dependencies
