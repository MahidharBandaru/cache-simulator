#include "../headers/stats.h"
void Stats::add_operation(int readCost, int writeCost)
{
    int prevRead, prevWrite;
    if (operationsReadPrefSum.size() != 0)
        prevRead = operationsReadPrefSum[operationsReadPrefSum.size() - 1];
    else
        prevRead = 0;
    if (operationsWritePrefSum.size() != 0)
        prevWrite = operationsWritePrefSum[operationsWritePrefSum.size() - 1];
    else
        prevWrite = 0;

    operationsReadPrefSum.push_back(readCost + prevRead);
    operationsWritePrefSum.push_back(writeCost + prevWrite);
}
double Stats::last_n_read(int n)
{
    int size = operationsReadPrefSum.size();
    int r = size - 1;
    int l = size - 1 - n;
    int ans = operationsReadPrefSum[r];
    if (l >= 0)
        ans -= operationsReadPrefSum[l];
    double avg = ans * 1.0 / n;
    return avg;
}

double Stats::last_n_write(int n)
{
    int size = operationsWritePrefSum.size();
    int r = size - 1;
    int l = size - 1 - n;
    int ans = operationsWritePrefSum[r];
    if (l >= 0)
        ans -= operationsWritePrefSum[l];
    double avg = ans * 1.0 / n;
    return avg;
}
int Stats::total_operations()
{
    // TODO: Check if read array and write array are of same size
    return operationsWritePrefSum.size();
}