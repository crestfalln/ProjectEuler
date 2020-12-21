#include <iostream>
#include <vector>
using namespace std;
int factorial(int a)
{
    if (a == 1 || a == 0)
        return 1;
    else
        return factorial(a-1)*a;
}
int main()
{
    const int num = 1000000-1;
    vector<int> arr = {0,1,2,3,4,5,6,7,8,9};
    int left = num;
    for(int i = 9; i>=0 ; i--)
    {
        int fac = factorial(i); 
        int q = left/fac;
        if(q!=0){
            left = left%fac;}
        cout << arr[q];
        arr.erase(arr.begin()+q);   
        
    }
    return 0;
}