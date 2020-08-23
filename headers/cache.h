#pragma once
class Cache
{
public:
    int readCycles = 0;
    int writeCycles = 0;
    int csize;
    bool lastEvict = 0;
    bool keyNotFound = 0;
    int evictKey;
    int evictValue;
    int lastOperationReadCycles = 0;
    int lastOperationWriteCycles = 0;
    int evictions = 0;

    Cache(int, int, int);
    virtual int get_key(int) = 0;
    virtual void set_key(int, int) = 0;
    virtual int free_capacity() = 0;
};