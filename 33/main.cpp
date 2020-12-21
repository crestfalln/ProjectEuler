#include <iostream>
using namespace std;
double match(int &n, int &d)
{
    double N1 = n/10, N2 = n%10;
    double D1 = d/10, D2 = d%10;
    
    if(N1 == D1 && D1 != 0)
        return N2/D2;
    if(N1 == D2 && D2 != 0)
        return N2/D1;
    if(N2 == D1 && D1 != 0)
        return N1/D2;
    if(N2 == D2 && D2 != 0)
        return N1/D1;
    else 
        return 0;
}
int main()
{
    //int result1 = 1 , result2 = 1 ;
    for(double D = 1; D < 100; D++)
        {
            for(double N = 1; N < D; N++)
            {
                int copyN = N; 
                int copyD = D;
                double temp = N/D;
                if(temp == match(copyN , copyD))
                {
                    cout << N << " , " << D << " \n";
                }
            }
        }
    //cout << result1 << endl << result2;
}


/*
                    for (int i = 2; i <= copyN; i++ )
                    {
                        while(copyN%i == 0 && copyD%i == 0)
                        {
                            copyN = copyN/i;
                            copyD = copyD/i;            
                        }
                    }
                    result1*=copyD;
                    result2*=copyN;
*/