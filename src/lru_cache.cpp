#include "../headers/lru_cache.h"
LRUCache::LRUCache(int capacity, int readCycles, int writeCycles) : Cache(capacity, readCycles, writeCycles) {}
void LRUCache::set_key(int key, int value)
{
    lastEvict = 0;
    // not present in cache
    if (keyLocation.find(key) == keyLocation.end())
    {
        // cache is full
        // have to evict something
        if (dq.size() == csize)
        {
            // delete least recently used element
            int last = dq.back();
            evictions++;
            lastEvict = 1;
            evictKey = last;
            evictValue = keyStore[last];
            dq.pop_back();
            keyLocation.erase(last);
            keyStore.erase(last);
        }
    }

    // present in cache
    else
        dq.erase(keyLocation[key]);

    // update reference
    dq.push_front(key);
    keyLocation[key] = dq.begin();
    keyStore[key] = value;
    lastOperationReadCycles = readCycles;
    lastOperationWriteCycles = writeCycles;
}

int LRUCache::get_key(int key)
{
    lastEvict = 0;
    keyNotFound = 1;
    // not present in cache
    if (keyLocation.find(key) == keyLocation.end())
    {
        return -1;
    }
    // present in cache
    // update reference and return value
    dq.erase(keyLocation[key]);
    dq.push_front(key);
    keyLocation[key] = dq.begin();
    keyNotFound = 0;
    lastOperationReadCycles = readCycles;
    lastOperationWriteCycles = 0;

    return keyStore[key];
}
int LRUCache::free_capacity()
{
    return csize - keyLocation.size();
}