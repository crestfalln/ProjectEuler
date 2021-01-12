#include <iostream>
#include "../prime.h"
#include <vector>
int sumVec(std::vector<int> &vec)
{
    int result = 0;
    for (int i = 0; i < vec.size(); i++)
        result += vec[i];
    return result;
}

int main()
{
    std::vector<int> list;
    const int num = 1000000;
    bool primeSet[num] = {0};
    primeSeive(primeSet, num);
    int count = 0;
    int result = 0;
    for (int i = num / 2 + num/10; i >= 2; i--)
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
