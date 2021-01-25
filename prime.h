#include <cmath>

void primeSeive(bool primeSet[], long num)
{
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
