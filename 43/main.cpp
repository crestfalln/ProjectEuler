#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

bool number[10] = {0};
int prime[] = {2, 3, 5, 7, 11, 13, 17};
int count = 0;
long result = 0;

void check(vector<int> perm)
{
    bool chec = false;
    for (int i = 0; i < sizeof(prime) / sizeof(int); i++)
    {
        for (int i = 0; i <= 6; i++)
        {
            if ((perm[i + 1] * 100 + perm[i + 2] * 10 + perm[i + 3]) % prime[i] == 0)
            {
                chec = true;
            }
            else
            {
                chec = false;
                break;
            }
        }
    }
    if (chec)
    {
        long tmp = 0;
        for (int i = 0; i < perm.size(); i++)
        {
            tmp = tmp * 10 + perm[i];
        }
        result += tmp;
    }
}
void permu(int stage = 0, vector<int> perm = {})
{
    bool tmp = 0;
    if (stage == 10)
    {
        check(perm);
        return;
    }
    else
    {
        for (int i = 0; i < sizeof(number) / sizeof(bool); i++)
        {
            if (stage == 0 & i == 0)
            {
                continue;
            }
            if (!number[i])
            {
                if (tmp)
                {
                    number[*(perm.end() - 1)] = false;
                    perm.pop_back();
                    tmp = 0;
                }
                number[i] = true;
                perm.push_back(i);
                tmp = 1;
                permu(stage + 1, perm);
            }
        }
    }
    number[*(perm.end() - 1)] = false;
    perm.pop_back();
    return;
}
int main()
{
    permu();
    cout << result;
}