# Sorting Algorithms Performance Benchmark

This repository contains a **C++ program** that implements and benchmarks several classical sorting algorithms. It is designed to help **compare execution times** of different sorting methods on arrays under various conditions.

## Features

- **Implemented Sorting Algorithms:**
  - Bubble Sort
  - Selection Sort
  - Insertion Sort
  - Merge Sort
  - Quick Sort (currently active in the main program)

- **Algorithm Timing & Analysis:**
  - Measures time to sort arrays in different scenarios:
    - Randomly ordered
    - Already sorted
    - Sorted in descending order
    - Reversed back to ascending order
  - Displays a clear summary of execution times.

- **Flexible Array Size:**
  - Specify the number of elements as a command-line argument.
  - Input data through standard input (`cin`) for flexibility.

- **Modular & Reusable Design:**
  - Sorting algorithms are implemented as separate functions.
  - Helper functions handle array printing, swapping, partitioning (Quick Sort), merging (Merge Sort), and timing.
  - Organized into headers (`include/`) and source files (`src/`) for clarity.

- **Customizable Sorting Order:**
  - All algorithms can sort arrays in **ascending or descending order**.

---

## Usage

1. **Compile the program:**

```bash
g++ src/main.cpp src/support.cpp -o sortAlgorithms
