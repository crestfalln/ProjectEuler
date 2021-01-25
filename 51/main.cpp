#include <iostream>
#include "../prime.h"
#include <cmath>
bool crDigits(int num, int *arr, int arrSize)
{
    for (unsigned int i = 1; num != 0; i++)
    {
        arr[arrSize - i] = num % 10;
        num /= 10;
    }
}
int digitsToNum(int *arr, int arrSize)
{
    int result = 0;
    for (int i = 0; i < arrSize; i++)
    {
        result *= 10;
        result += arr[i];
    }
    return result;
}
bool arrcpy(int *arr1, int *arr2, int size)
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr1[i];
    }
}
int main()
{
    const int size = 1000000;
    bool primeSet[size];
    primeSeive(primeSet, size);
    int count = 0;
    
    for (int i = 2; i < size; i++)
    {
        if (!primeSet[i])
        {
            int digitCount = log10(i) + 1;
            int digits[digitCount];
            int cpDigits[digitCount];
            crDigits(i, digits, digitCount);
            for (int j = 0; j < digitCount; j++)
            {
                for (int k = 0; k < digitCount; k++)
                {
                    if (j == k)
                        continue;
                    arrcpy(digits, cpDigits, digitCount);
                    for (int l = 0; l < 10; l++)
                    {
                        cpDigits[j] = l;
                        cpDigits[k] = l;
                        if(primeSet[digitsToNum(cpDigits , digitCount)])
                            {
                                count++;
                                if(count == 7)
                                {
                                    std::cout << digitsToNum(digits , digitCount) << std::endl;
                                    return 0;
                                }
                            }
                    }
                }
            }
        }
    }
}