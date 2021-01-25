#include <vector>
#include <cmath>

void primeSeive(std::vector<bool> &primeSet, long num)
{
    for(int i = 0 ; i < num ; i++)
        primeSet.push_back(0);
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (!primeSet[i])
        {
            for (int u = i * i; u < num; u += i)
            {
                primeSet[u] = true;
            }
        }
    }
}
