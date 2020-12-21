#include <iostream>
#include <cmath>
#include <sstream>
using namespace std;
int digits(long int num)
{
    return floor(log10(num)) + 1;
}
bool checkPandigital(int num, long int &pandigital, bool numbers[])
{
    do
    {
        int digit = num % 10;
        num /= 10;
        if (digit == 0)
            return false;
        if (numbers[digit])
        {
            return false;
        }
        numbers[digit] = true;
    } while (num != 0);
    return true;
}
int main()
{
    long result = 0;
    for (int num = 1; num <= 10000; num++)
    {
        long temp = num;
        bool cont = true;
        while (temp != 0)
        {
            if (temp == 9)
            {
                cont = false;
            }
            temp /= 10;
        }
        if (cont)
        {
            continue;
        }
        bool numbers[10] = {0};
        long int pandigital = 0;
        for (int i = 1;; i++)
        {
            int temp(num * i);
            if (checkPandigital(temp, pandigital, numbers))
            {
                pandigital *= int(pow(10, digits(temp)));
                pandigital += temp;
            }
            else
            {
                break;
            }
        }
        if (pandigital > result)
        {
            result = pandigital;
        }
    }
    cout << result;
}