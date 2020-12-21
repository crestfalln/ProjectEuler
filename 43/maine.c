#include <stdio.h>
main()
{
    int i;
    int result = 0;
    scanf("%d", &i);
    while(i)
    {
        result = result*10 + i%10;
        i/=10;
    }
    printf("%d",result);
}