#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
    const int input = 5;
    int limit;
    for(int i = 1; ; i++)
    {
        if(i*pow(9,input) < pow(10,i+1)){
            limit = (i-1)*pow(9,input);
            break;
        }
    }
    int powerNo[11];
    for(int i = 0; i < 10; i++)
    {
        powerNo[i] = pow(i, input);
    }
    int result = 0;
    for(int i = 2; i <= limit; i++)
    {
        int digitSum = 0;
        int num = i;
        while(num > 0)
        {
            if(digitSum > i)
                break;
            int temp = num%10;
            num = num/10;
            temp = powerNo[temp];
            digitSum += temp; 
        }
        if(digitSum == i){
            result = result + i;
        }
    }
        cout << result << "\n";
}