#include <iostream>
#include "list.h"

const int num = 10000;
list digitList[num];

int check_if_permutation(int a, int b , int c)
{
    digitList[a].digitSet(a);
    digitList[b].digitSet(b);
    digitList[c].digitSet(c);

    for (int i = 0; i < 10; i++)
    {
        if (!(digitList[a].digits[i] == digitList[b].digits[i] && digitList[b].digits[i] == digitList[c].digits[i]))
            return false;
    }
    return true;
}

int main()
{
    bool primeSet[num] = {0};
    primeSeive(primeSet, num);
    for (int i = 1000; i < num; i++)
    {
        if (!primeSet[i])
        {
            for (int j = i + 1; j < num; j++)
            {
                if (!primeSet[j])
                {
                    int k = 2 * j - i;
                    if (k > num)
                        break;
                    if (primeSet[k])
                        continue;
                    if (check_if_permutation(i , j , k))
                    {
                        std::cout << i << j << k << std::endl;
                    }
                }
            }
        }
    }
}