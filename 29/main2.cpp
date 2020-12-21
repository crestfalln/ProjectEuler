#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
using namespace std;

int main()
{
    const int input = 100;
    int limitForCheck = floor(sqrt(100));
    pair<int,int> explist[input+1];
    bool list[input+1] = {0};
    for(int i = 2; i <= limitForCheck; i ++)
    {
       // if(list[i]){
         //   continue;
        //}
        for(int k = 2; ; k++)
        {
            int temp = pow(i,k);
            if(temp >= input){
                break;
            }
            list[temp] = 1;
            explist[temp] = make_pair(i,k);
        }
    }
    int add = input - 1;
    int sum = add*add;
    for(int i = 2; i <= input ; i++)
    {
        if(list[i])
        {
            int temp =  (input/(explist[i].second)) - 1 ;
            sum = sum - temp;
        }
    }
//    cout << sum;
    double a = pow(9,100), b = pow(81,50);
    if(a == b)
    { 
        cout << endl;
    }
}