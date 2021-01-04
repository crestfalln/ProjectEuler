#include <iostream>
#include <cmath>

int checkPent(long num)
{
    double n = (sqrt(24 * num + 1) + 1) / 6;
    if(n == int(n))
    {
        return int(n);
    }
    return 0;
}

int checkHex(long num)
{
    double n = (sqrt(8*num + 1) + 1)/4;
    if(n == int(n))
    {
        return int(n);
    }
    return 0;
}

long genTriangle(long n)
{
    return n*(n+1)/2;
}

int main()
{
   for(int i = 286; ; i++)
   {
       long triangleNum = genTriangle(i);
       if(checkHex(triangleNum) && checkPent(triangleNum))
       {
           std::cout << triangleNum;
           return 0;
       }
   }
}