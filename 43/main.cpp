#include <iostream>
using namespace std;
bool lookup[10] = {0};
int input = 3;
void premutations(int stage = 0, long num = 0)
{
    if (stage == 8)
    {
        cout << num << endl;
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (!lookup[i])
        {
            num = num * 10 + i;
            lookup[i] = true;
            premutations(stage + 1, num);
        }
        else{
        lookup[i] = false;
        num = num/10; 
        return;
        }
    }
}
int main()
{
    premutations();
}