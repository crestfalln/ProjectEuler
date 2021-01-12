#include <iostream>
#include "../prime.h"
#include <vector>
long sumVec(std::vector<long> &vec)
{
    long result = 0;
    for (long i = 0; i < vec.size(); i++)
        result += vec[i];
    return result;
}

int main()
{
    long num;
    std::cin >> num;
    std::vector<long> list; 
    std::vector<bool> primeSet ;
    primeSeive(primeSet, num);
    long count = 0;
    long result = 0;
    for (long i = num / 2 + num/10; i >= 2; i--)
    {
        if (!primeSet[i])
        {
            list.push_back(i);
            if (sumVec(list) >= num)
                list.erase(list.begin());
            if (!primeSet[sumVec(list)] && list.size() > count)
            {
                result = sumVec(list);
                count = list.size();
            }
            if (i == 2)
            {
                while (!list.size() >= count)
                {
                    list.erase(list.begin());
                    if (!primeSet[sumVec(list)] && list.size() > count)
                    {
                        result = sumVec(list);
                        count = list.size();
                        break;
                    }
                }
            }
        }
    }
    std::cout << result;
}
