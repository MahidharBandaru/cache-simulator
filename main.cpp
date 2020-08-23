#include <iostream>

using namespace std;

#include "headers/system.h"
#include "headers/cache.h"
#include "headers/lru_cache.h"
#include "headers/config.h"

int main()
{
    System system;
    system.add_cache(LRUCache(L1_CACHE_SIZE, L1_CACHE_READ_LATENCY, L1_CACHE_WRITE_LATENCY));
    system.add_cache(LRUCache(L2_CACHE_SIZE, L2_CACHE_READ_LATENCY, L2_CACHE_WRITE_LATENCY));
    system.add_cache(LRUCache(L3_CACHE_SIZE, L3_CACHE_READ_LATENCY, L3_CACHE_WRITE_LATENCY));

    for (int i = 0; i < OPERATIONS; i++)
    {
        int key = rand() % KEY_RANGE;
        int val = rand() % VALUE_RANGE;
        int op = rand() % 2;
        if (op == 0)
        {
            system.get_key(key);
        }
        else
        {
            system.set_key(key, val);
        }
        if (i % STATS_PRINT_FREQ == 0)
        {
            system.get_stats();
        }
    }

    return 0;
}