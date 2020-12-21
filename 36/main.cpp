#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
class number
{
public:
    number(int b10);
    int reverse();
    int base10;
    bool base10R;
    vector<bool> base2;
    bool base2R;
};
int number::reverse()
{
    int temp = base10;
    int digits = floor(log10(temp));
    int rev = 0;
    for (int i = 0; temp != 0; i++)
    {
        rev += ((temp % 10) * (pow(10, digits - i)));
        temp /= 10;
    }
    if (rev == base10)
    {
        base10R = true;
    }
}
number::number(int b10)
{
    base10 = b10;
    base10R = false;
    base2R = false;
    reverse();
    if (base10R)
    {
        while (b10 != 0)
        {
            base2.push_back(b10 % 2);
            b10 /= 2;
        }
        for (int i = 0; i < base2.size(); i++)
        {
            if (base2[i] == base2[base2.size() - i - 1])
            {
                base2R = true;
            }
            else
            {
                base2R = false;
                break;
            }
        }
    }
}
int main()
{
    const int input = 1000000;
    int result = 0;
    for (int i = 1; i < input; i++)
    {
        number num = i;
        if (num.base2R && num.base10R)
        {
            result += num.base10;
        }
    }
    cout << result;
}