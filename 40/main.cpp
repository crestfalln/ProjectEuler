#include <iostream>
using namespace std;
long pow10(int num)
{
    int result = 1;
    while (num != 0)
    {
        num--;
        result *= 10;
    }
    return result;
}
int main()
{
    const int input = 1000000;
    int count = 0;
    int result = 1;
    int i = 1;
    int lim = 0;
    int digit = 1;
    while(1)
    {
        if(i >= pow10(lim) && i < pow10(lim+1))
        {
            count+=(lim+1);
            if(count >= digit)
            {
                int dupi = i;
                cout << i << " ";
                int difference = count - digit;
                cout << difference << endl;
                while(difference)
                {
                    dupi/=10;
                    difference--;
                }
                result*=dupi%10;
                digit*=10;
            }
            if(count > input)
                break;
            i++;
        }
        else
        {
            lim+=1;
        }
    }
    cout << result;
}