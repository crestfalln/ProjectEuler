#include<iostream>
#include<vector>
using namespace std;

const int lim = 28123;

void getDivSum(int array[30000])                  //gets sum of all divisors and stores it into an array
{
    for (int i = 2; i <= 30000; i ++)
    {
        int sum = 0;
        int copy = i;
        for (int t = 1; t<copy; t++)
        {
            if(i%t==0)
            {
                copy = i/t;
                if(copy != t){
                sum= sum+t+copy;
                }
                else{
                    sum=sum+t;
                }
            }
        }
        array[i]=sum-i;
    }
}
void getAbundant(vector<int> &abundant            //gets all abundant numbers and stores them in a vector
                        , int array[30000])          
{
    for(int i = 1; i <= lim; i++)
    {  
        if(array[i]>i)
        {
            abundant.push_back(i);
        }
    }
}

int main()
{
    
    int array[30000];
    vector<int> abundant;
    bool ifAbundantSum[limit] = {0};                  //lookup table is true for values expressed in abundant nos. 
    long int sum = 0;
    getDivSum(array);getAbundant(abundant,array);      
    for(int i = 0 ; i < abundant.size() ; i++)        //nested loops finds all possible sums in abundant and
    {
        for(int k = i ; k < abundant.size() ; k++)
        {
            int tempSum = abundant[i]+abundant[k];      
            if(tempSum <= lim){
                ifAbundantSum[tempSum]=1; }
            else{
                break;}
        }
    }
                                                      //stores them in the ifAbundantSum lookup table
    for(int i = 1 ; i <=lim; i++ )                    //finds the sum using the lookup table
    {
        if(!ifAbundantSum[i])
        sum = sum + i;
    }
    cout << sum;
}