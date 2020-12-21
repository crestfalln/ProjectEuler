#include <iostream>
#include <cmath>
using namespace std;
int facArr[10];
int factorial(int num)
{
    if(num == 1)
        return 1;
    else
    {
        return num*factorial(num-1);
    }
}
int facSum(int num)
{
    int sum = 0;
    int digits; 
    if(num == 1){
        digits = 1;
    }
    else{
        digits = ceil(log10(num));
    }
    for(int i = 0; i < digits; i++)
    {
        sum+=facArr[num%10];
        num/=10;
    }
    return sum;
}
int main()
{
    int result = 0;
    facArr[0]=1;
    for(int i = 1; i <= 9; i++)
    {
        facArr[i] = factorial(i);
    }
    for(int i = 3; i < 9999999; i++)
    {
        if(i == facSum(i))
        {
            result+=i;
        }
    }
    cout << result;

}