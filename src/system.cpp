#include "../headers/system.h"

int System::get_key(int key)
{
    operations++;
    int cacheIndex = 0;
    operationReadCost = 0;
    operationWriteCost = 0;
    int value = -1;
    bool found = 0;
    for (int cacheIndex = 0; cacheIndex < caches.size(); cacheIndex++)
    {
        auto &cache = caches[cacheIndex];
        int tValue = cache.get_key(key);
        operationReadCost += cache.lastOperationReadCycles;
        operationWriteCost += cache.lastOperationWriteCycles;
        if (!cache.keyNotFound)
        {
            if (cacheIndex)
            {
                set_key(key, value, cacheIndex - 1);
            }
            value = tValue;
            found = 1;
            break;
        }
    }
    if (!found)
    {
        // element needs to be read from memory and put into cache
        // let the read value be value
        value = 0; // assume this is somehow read from memory
        operationReadCost += MEMORY_READ_LATENCY;
        set_key(key, value, 0);
    }
    stats.add_operation(operationReadCost, operationWriteCost);

    return value;
}
void System::set_key(int key, int value, int level = 0)
{
    if (level >= caches.size())
        return;
    auto &cache = caches[level];
    cache.set_key(key, value);
    operationReadCost += cache.lastOperationReadCycles;
    operationWriteCost += cache.lastOperationWriteCycles;

    if (cache.lastEvict)
    {
        set_key(cache.evictKey, cache.evictValue, level + 1);
    }
}
void System::set_key(int key, int value)
{
    operations++;
    operationReadCost = 0;
    operationWriteCost = 0;
    set_key(key, value, 0);
    stats.add_operation(operationReadCost, operationWriteCost);
}
void System::add_cache(const LRUCache &cache)
{
    caches.push_back(cache);
}
void System::get_stats()
{
    cout << "********** STATISTICS **********" << endl;
    cout << "Operations so far: " << operations << endl;
    cout << "Average read time for last " << STATS_PRINT_FREQ << " operations: " << stats.last_n_read(STATS_PRINT_FREQ) << endl;
    cout << "Average write time for last " << STATS_PRINT_FREQ << " operations: " << stats.last_n_write(STATS_PRINT_FREQ) << endl;
    cout << endl;
    for (int i = 0; i < caches.size(); i++)
    {
        cout << "L" << i + 1 << " free capacity: " << caches[i].free_capacity() << endl;
        cout << "L" << i + 1 << " eviction count: " << caches[i].evictions << endl;
        cout << endl;
    }
}
