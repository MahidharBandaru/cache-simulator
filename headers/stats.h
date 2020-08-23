#pragma once
#include <vector>
#include <iostream>
class Stats
{
    std::vector<int> operationsReadPrefSum;
    std::vector<int> operationsWritePrefSum;

public:
    void add_operation(int, int);
    int total_operations();
    double last_n_read(int);
    double last_n_write(int);
};