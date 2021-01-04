#include <iostream>
#include <cmath>

int pent(int num) //returns pentagonal number with the position = num
{
    return num * (3 * num - 1) / 2;
}
bool checkPent(int num) //checks if an input number is pentagonal or not
{
    double n = (sqrt(24 * num + 1) + 1) / 6;
    if (n == (unsigned int)(n))
        return true;
    else
        return false;
}

int main()
{
    for (int i = 1;; i++)
    {
        long sum = pent(i);
        for (int u = 1; u < i; u++)
        {
            long diff = pent(u);
            if (checkPent((sum + diff) / 2) && checkPent((sum - diff) / 2))
            {
                std::cout << diff;
                return 0;
            }
        }
    }
}
