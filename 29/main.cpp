#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    vector<double> vec;
    for(int i = 2; i <=100; i++)                  
    {
        for(int k = 2; k<=100; k++)
        {
            vec.push_back(pow(i,k));
        }
    }
    sort(vec.begin(), vec.end());
    for(int i = 0 ; ; i++ )
    {
        if(i >= vec.size()-1)
            break;
        while(vec[i]==vec[i+1])
        {
            vec.erase(vec.begin()+i);
        }
    }
    cout << vec.size();
    if(pow(1.9,12)== pow(2,12))
        cout << "help";
}