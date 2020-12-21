#include <iostream>
using namespace std;
int arr[9] = {1,2,3,4,5,6,7,8,9};
bool table[9999] = {0};
void output()
{
    for(int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
void permutations(int k)
{
    if(k==1)
    {
        int multi = (10*arr[0] + arr[1]) * (100*arr[2] + 10*arr[3] + 1*arr[4]);
        int rest = 1000*arr[5] + 100*arr[6] + 10*arr[7] + 1*arr[8];
        if(multi==rest)
        {
            table[rest] = 1;
        }
        int multi2 = arr[0] * (1000*arr[1] + 100*arr[2] + 10*arr[3] + 1*arr[4]);
        int rest2 = 1000*arr[5] + 100*arr[6] + 10*arr[7] + 1*arr[8];
        if(multi2==rest2)
        {
            table[rest] = 1;
        }
    }
    else
    {
        permutations(k-1);
        for(int i = 0; i < k-1; i++)
        {
            if(k%2 == 0)
            {
                swap(arr[i],arr[k-1]);
            }
            else
            {
                swap(arr[0],arr[k-1]);
            }
            permutations(k-1);
        }
    }
    
}

int main()
{
    permutations(9);
    int sum = 0;
    for(int i = 0; i < 9999; i++)
    {
        if(table[i])
        {
            sum+=i;
        }
    }
    cout << sum;
}