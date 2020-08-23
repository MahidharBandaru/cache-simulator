#pragma once
#include <unordered_map>
#include <list>
#include <iostream>
#include "cache.h"

class LRUCache : public Cache
{
    std::list<int> dq;

    std::unordered_map<int, std::list<int>::iterator> keyLocation;
    std::unordered_map<int, int> keyStore;

public:
    LRUCache(int, int, int);
    int get_key(int) override;
    void set_key(int, int) override;
    int free_capacity() override;
};