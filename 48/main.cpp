#include <iostream>
#include <cmath>

double reduce(double &num , int reduceTo)
{
    num = num - floor(num/pow(10 , reduceTo)) * pow(10 , reduceTo);
    return num;
}

double power(int a , int b)
{
    double result = a ;
    for(int i = 2; i <=b; i++)
    {
        if(log10(result) > 10)
            reduce(result , 10);
        result*=a;
    }
    return result;
}

int main()
{
    double sum = 0;
    std::cout.precision(10);
    for(int i = 1; i <=1000; i++)
    {
        if(log10(sum) > 10)
            reduce(sum , 10);
        sum+=power(i , i);
    }
    std::cout << sum;
}