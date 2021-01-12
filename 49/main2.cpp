#include <iostream>
#include <vector>
#include <map>
#include "../prime.h"

int check_if_permutation(int a, int b)
{
    if (a == 0 || b == 0)
        return 0;
    int tmp1 = a;
    int tmp2 = b;
    int digits_num1[10] = {0};
    int digits_num2[10] = {0};
    while (tmp1 != 0)
    {
        digits_num1[tmp1 % 10]++;
        digits_num2[tmp2 % 10]++;
        tmp1 /= 10;
        tmp2 /= 10;
    }

    for (int i = 0; i < 10; i++)
    {
        if (digits_num1[i] != digits_num2[i])
            return 0;
    }
    return a;
}

int main()
{
    const int num = 10000;
    bool primeSet[num] = {0};
    primeSeive(primeSet, num);
    for (int i = 1000; i < num ; i++)
    {
        if (!primeSet[i])
        {
            for (int j = i + 1; j < num; j++)
            {
                if (!primeSet[j])
                {
                    int k = 2 * j - i;
                    if (k  > num )
                        break;
                    if(primeSet[k])
                        continue;
                    if (check_if_permutation(check_if_permutation(i, j), k))
                    {
                        std::cout << i << j << k << std::endl;
                    }
                }
            }
        }
    }
}