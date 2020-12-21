#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int check = 1000000;
vector<bool> prime(check, 0);
void seive()
{
    for (int i = 2; i <= sqrt(check); i++)
    {
        if (prime[i])
        {
            continue;
        }
        int temp = pow(i, 2);
        for (int k = 1; temp < check; k++)
        {
            prime[temp] =true;
            temp += i;
        }
    }
}
int main()
{
    prime[1] = true;
    seive();
    int count = 0;
    int result = 0;
    for (int i = 1; i < prime.size() && count < 11; i++)
    {
        if (!prime[i])
        {
            int ten = 10;
            bool temp = false;
            for (int k = 1; i / ten > 0; k++)
            {
                if (!prime[i % ten] && !prime[i / ten])
                {
                    temp = true;
                }
                else
                {
                    temp = false;
                    break;
                }
                ten *= 10;
            }
            if (temp)
            {
                count++;
                result += i;
            }
        }
    }
    cout << result;
}