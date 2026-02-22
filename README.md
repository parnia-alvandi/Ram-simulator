# RAM Simulator

A memory (RAM) simulator implementing various Page Replacement Algorithms.

## Features
- Supports the following algorithms:
  - FIFO (First-In, First-Out)
  - LRU (Least Recently Used)
  - Optimal
  - Clock
- Page table and frame management
- Easily extensible — add new algorithms with minimal effort

## How to Build
```bash
mkdir build && cd build
cmake ..
make
```

## How to Run
```bash
./ram_sim
```

You will be prompted to enter the number of frames and choose a replacement algorithm. The simulator will then run through a predefined reference string and display the memory state after each page access, along with the total number of page faults.

## Project Structure
```
├── include/
│   ├── MemoryManager.h
│   ├── PageTable.h
│   ├── Frame.h
│   ├── ReplacementAlgorithm.h
│   ├── FIFO.h
│   ├── LRU.h
│   ├── Optimal.h
│   └── Clock.h
└── src/
    ├── main.cpp
    ├── MemoryManager.cpp
    ├── PageTable.cpp
    ├── Frame.cpp
    ├── ReplacementAlgorithm.cpp
    ├── FIFO.cpp
    ├── LRU.cpp
    ├── Optimal.cpp
    └── Clock.cpp
```

## Adding a New Algorithm

1. Create a new header in `include/` inheriting from `ReplacementAlgorithm`.
2. Implement the `accessPage(int page)` method in `src/`.
3. Register the new algorithm in `main.cpp`.
