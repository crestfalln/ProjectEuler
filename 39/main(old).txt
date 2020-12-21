#include <iostream>
using namespace std;

int main()
{
    int peri[1000] = {0};
    for (int c = 1; c < 500; c++)
    {
        bool excess = false;
        for (int a = 1; a < c; a++)
        {
            if (excess)
            {
                break;
            }
            for (int b = a; b < c; b++)
            {
                int perimeter = a + b + c;
                if (perimeter >= 1000)
                {
                    excess = true;
                    break;
                }
                if (a * a + b * b == c * c)
                {
                    peri[perimeter]++;
                }
            }
        }
    }
    int count = 0;
    int result = 0;
    for(int i = 1; i < 1000; i++)
    {
        if(count < peri[i])
        {
            count = peri[i];
            result = i;
        }
    }
    cout << result;
}