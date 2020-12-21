#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int array[10001]={0};
    for (int i = 2; i < 10000; i ++)
    {
        int sum = 0;
        int copy = i;
        for (int t = 1; t<copy; t++)
        {
            if(i%t==0)
            {
                copy = i/t;
                if(copy != t)
                {
                sum= sum+t+copy;
                }
                else
                {
                    sum=sum+t;
                }
                
            }
        }
        array[i]=sum-i;
    }
    cout << array[220] << endl;
    cout << array[284] << endl;
    long int sum = 0;
    for(int i = 2; i<10000; i++)
    {
        if(array[i] < 10000){
        if(array[array[i]]==i && array[i]!=i)
        {
            sum = sum + array[i]+i; 
            array[i]=0;
        }}
    }
    cout << sum;
}