#include<iostream>
#include<cmath>
using namespace std;
const int input = 1000000;
bool prime[input] = {0};
int rotate(int num)
{
    int digits;
    digits = floor(log10(num));
    return ((num%10)*pow(10,digits))+(num/10);
}
void seive()
{
    for(int i = 2; i <= sqrt(input); i++)
    {
        if(!prime[i])
        {
            int power = pow(i,2);
            do
            {
                prime[power] = 1;
                power+=i;
            }while(power < input);
        }
    }
}
int main()
{
    int count = 0;
    seive();
    for(int i = 2; i < input; i++)
    {
        if(!prime[i])
        {
            int cpy = i;
            bool test;
            do
            {
                test = 0;
                cpy = rotate(cpy);
                if(prime[cpy])
                    break;
                test = 1;
            }while(cpy != i);
            if(test)
            {
               // cout << i << endl;
                count++;
            }
        }
    }
    //cout << count;
}