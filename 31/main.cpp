#include<iostream>
#include<vector>
using namespace std;
const int input = 200;
int coins[] = {200, 100, 50, 20, 10, 5, 2, 1};
const int size = sizeof(coins)/sizeof(coins[0]);
int arr[size] = {0};
int arrSum(int index)
{
    int sum=0;
    for(int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum - arr[index];
}
int arrSum()
{
    int sum=0;
    for(int i = 0; i < size; i++)
    {
        sum+=arr[i];
    }
    return sum;
}
void permu(int index, int& count)
{
    if(index == size)
    {
        if(arrSum() == input)
            count++;
        return;
    }
    for(int i = 0; i <= (input-arrSum(index))/coins[index]; i++)
    {
        arr[index]=(i*coins[index]);
        permu(index+1,count);
    }
}
int main()
{
    int count = 0;
    permu(0, count);
    cout << count;
}