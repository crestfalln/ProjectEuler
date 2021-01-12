#include "../prime.h"
class list{
public:
    bool init = 0;
    void digitSet(int num);
    unsigned char digits[10] = {0};
};

void list::digitSet(int num)
{
    if (!init)
    {
        while (num != 0)
        {
            digits[num % 10]++;
            num /= 10;
        }
    }
    init = 1;
}