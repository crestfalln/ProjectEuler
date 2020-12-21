#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream inputFile("input.txt");
    char a;
    string input;
    getline(inputFile,input);
    long result = 1;
    for(int i = 0; i < input.size() - 13; i++)
    {
        long temp = 1;
        for(int k = 0; k < 13; k++)
        {
            temp = temp * (input[k+i]-'0');
        }
        if(temp > result)
        {
            result = temp;
        }
    }
    cout << result;
}