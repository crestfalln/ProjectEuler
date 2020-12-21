#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main()
{
    stringstream ss;
    int i = 1;
    int temp = 1;
    int result = 1;
    do
    {
        ss << i;
        i++;
    } while(ss.str().size() <= 1000000);
    for(int k = 0 ; k <= 6 ; k++)
    {
        char cha = ss.str()[temp-1];
        int og;
            {
                og = cha -'0';
                cout << og << endl;
                result*=og;
            }
        temp*=10;
    }
    cout << result;
}