#include <iostream>
#include <vector>
#include <cmath>

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
bool factorizable(int num, int factors_to_check, std::vector<bool> &primeSet)
{
    int factors = 0;
    for (int i = 2; num != 1 && i < primeSet.size(); i++)
    {
        if (primeSet[i] && num % i == 0)
        {
            factors++;
            while (num % i == 0)
                num /= i;
        }
        if (factors > factors_to_check)
            return false;
    }
    if(num != 1)
        factors++;
    if (factors == factors_to_check)
        return true;
    return false;
}
int answer(int factors_to_check, std::vector<bool> &primeSet)
{
    bool truth = false;
    for (int num = 2;; num++)
    {
        for (int i = 0; i < factors_to_check; i++)
        {
            if (factorizable(num + i, factors_to_check, primeSet))
                truth = true;
            else
            {
                truth = false;
                num += i;
                break;
            }
        }
        if (truth)
            return num;
    }
    return 0;
}

int main()
{
    std::vector<bool> primeSet;
    primeSeive(primeSet, 100);
    std::cout << answer(4, primeSet);
}