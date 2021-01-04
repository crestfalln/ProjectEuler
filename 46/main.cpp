#include <iostream>
#include <cmath>
#include <vector>

void primeSeive(std::vector<bool> &primeSet, int num)
{
    for (int i = 0; i < num; i++)
    {
        primeSet.push_back(true);
    }
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (primeSet[i])
        {
            for (int u = i * i; u < num; u += i)
            {
                primeSet[u] = false;
            }
        }
    }
}

int goldbachNo(int prime, int square)
{
    return prime + 2 * square * square;
}

int main()
{
    std::vector<bool> primeSet;
    primeSeive(primeSet, 6000);
    for (int i = 3; i < primeSet.size(); i += 2)
    {
        int sum; 
        if (!primeSet[i])
        {
            sum = 0;
            for (int u = 2; u < i; u++)
            {
                if(sum == i)
                    break;
                if (primeSet[u])
                {
                    for(int l = 1; ; l  )
                    {
                        sum = goldbachNo(u , l);
                        if(sum >= i)
                            break;
                    }
                }
            }
            if(sum != i)
            {
                std::cout << i;
                return 0;
            }
        }
    }
}