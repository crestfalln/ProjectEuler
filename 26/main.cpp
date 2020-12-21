#include <iostream>
#include <vector>
using namespace std;

int check(int val, vector<int> &vec)
{
    for(int i = 0 ; i < vec.size() ; i++ )
    {
        if(vec[i]==val)
        {
            return i;
        }
    }
    return -1;
}
int remainder(int nval, int dval , vector<int> &vec)
{
    if(nval < dval){
        nval = nval*10;
    }
    while(nval < dval)
    {
        nval=nval*10;
        vec.push_back(0);
    }
    int rem = nval%dval;
    if(rem == 0){
        return 0;
    }
    if(check(rem,vec)==-1)
    {
        vec.push_back(rem);
        return remainder(rem,dval,vec);
    }
    return vec.size() - check(rem,vec);
}
int main()
{
    int temp= 0 , result = 0 , count = 0;
    for(int i = 2 ; i <=10000; i++)
    {
        vector<int> vec;
        temp = remainder(1,i,vec);
        if(temp > count){
            count = temp;
            result = i;
        }
    }   
    cout << result;
    //cout << remainder(1,983);
}