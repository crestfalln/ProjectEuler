#include<iostream>
int main()
{
    int input = 1001;
    int num = (input+1)/2;
    long int sum = 1; 
    for(int i = 2; i <= num; i++)
    {
        sum = sum + 4*((4*i*i) - (7*i) + (4));
    }
    std::cout << sum;
}