## Cache Simulation System

### Assumptions

- The cache is exclusive - Upon eviction from Li, we insert this evicted into Li+1.
- If found at a deeper lever during get_key, we don't propagate it up all the way, but by just one level.
- In case a key is found in none of the levels, it exists in memory and we fetch it from there and call set_key to place it in our cache.
- The caches use LRU replacement policy for evictions
### To Run
- Compile: `g++ --std=c++11 src/*.cpp main.cpp` from project root.
- Run: `./a.out`

### Methods 
- int get_key(int) - Return the value of pair(key, value)
- void set_key(int, int) - Set the value of pair(key, value)
- void get_stats() - Prints the stats to terminal

### Config
- Change the constants in config.h to change the parameters of executions
- We have the following parameters
- CACHE_SIZE
- CACHE_READ_LATENCY
- CACHE_WRITE_LATENCY
- MEMORY_READ_LATENCY
- KEY_RANGE - We choose keys from [0, KEY_RANGE - 1] for all our get/set operations.
- VALUE_RANGE - We choose values from [0, VALUE_RANGE - 1] for all our get/set operations.
- OPERATIONS - Total number of operations to simulate
- STATS_PRINT_FREQ - After every STATS_PRINT_FREQ operations we print the stats of the Simulation.

