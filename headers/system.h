#pragma once
#include <vector>
#include <iostream>

#include "lru_cache.h"
#include "stats.h"
#include "config.h"

using namespace std;

class System
{
    std::vector<LRUCache> caches;
    Stats stats;
    int operationReadCost = 0;
    int operationWriteCost = 0;
    int operations = 0;
    void set_key(int, int, int);

public:
    int get_key(int);
    void set_key(int, int);
    void add_cache(const LRUCache &cache);
    void get_stats();
};