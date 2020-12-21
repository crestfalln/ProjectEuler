#include <iostream>
using namespace std;
int main()
{
    long int num = 600851475143;
    int k;
    for(int i = 2; num != 1; i++)
    {
        do
        {
            long int temp = num%i;
            if(temp == 0)
            {
                num = num/i;
            }
            else
                break;
        }while(1);
        k = i;
    }
    cout << k;
}