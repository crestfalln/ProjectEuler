#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
vector<bool> array;
void makePrime()
{
    const long int num = 100000;
    for(int i = 0; i < num; i++)
    {
        array.push_back(false);
    }
    int lim = floor(sqrt(num));
    for(int i = 2; i <= lim; i++)
    {
        int temp = i*i;
        for(int k = 1; temp <= num; k++)
        {
            array[temp] = true;
            temp = temp + i;
        }
    }
}

int calcQuad(const int &a, const int &b, const int &n)
{
    return (n*n)+(a*n)+b;
}

int main()
{
    int count = 0;
    int result; 
    makePrime();
    for(int a = -1000; a <= 1000 ; a++)
    {
        for(int b = 2; b <= 1000 ; b++)
        {
            int tempCount = 0;
            for(int n = 0 ; n <= 1000; n++)
            {
                int temp = calcQuad(a,b,n);
                if(temp < 0){
                    break;
                }
                if(array[temp] ){
                break;
            }
                tempCount++;
            }
            if(tempCount>count){
                count = tempCount;
                cout << a << " " << b << " " << count << "\n";
                result = a*b;
            }
        }
    }
    cout << result;
}