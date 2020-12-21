#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
#include <fstream>
using namespace std;
const int input = 9999999;
 void primeSeive(vector<bool>& prime)
{
    for (int i = 2; i < sqrt(input); i++)
    {
        if (!prime[i])
        {
            int k = i * i;
            while (k < input)
            {
                prime[k] = true;
                k+=i;
            }
        }
    }
}
bool isPandigital(int num ,const int tol)
{
    int digits = tol;
    vector<bool> digit(digits+1,0);
    while(digits != 0)
    {
        int temp = num%10;
        if(digit[temp] == true || temp == 0 || temp > tol)
        {
            return false;
        }
        digit[temp] = true;
        num/=10;
        digits--;
    }
    return true;
}
int main()
{
    vector<bool> prime(input+1,0);
    //primeSeive(prime);
    for(int i = 1000000; i < 9999999; i++)
    if( isPandigital(i,7) )
    {
        cout << i << "\n";
    }
}
#include <iostream>
#include <gmp.h>
#include <chrono>
auto start = std::chrono::high_resolution_clock::now();
using namespace std;
int result;
void printArr(int a[], int n)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp = temp*10 + a[i];
    }
    mpz_t  integ;
    mpz_init(integ);
    mpz_set_si(integ,temp);
    if(mpz_probab_prime_p(integ, 25) && temp > result)
    {
        result = temp;
    }
     mpz_clear(integ);   
} 
void heapPermutation(int a[], int size, int n)
{
    if (size == 1) {
        printArr(a, n);
        return;
    }
 
    for (int i = 0; i < size; i++) {
        heapPermutation(a, size - 1, n);
        if (size % 2 == 1)
            swap(a[0], a[size - 1]);
        else
            swap(a[i], a[size - 1]);
    }
}
 
int main()
{
    int a[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof a / sizeof a[0];
    heapPermutation(a, n, n);
    cout << result << "\n";
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time: " << duration.count();
    return 0;
}
#include <iostream>
#include <chrono>
using namespace std;
auto start = std::chrono::high_resolution_clock::now();
bool digitUsed[8] = {0};
bool IsPrime(int n)
{
	if (n % 2 == 0)
		return (n == 2);

	for (int d = 3; d * d < n; d += 2)
		if (n % d == 0)
			return false;

	return true;
}

bool Perm(int num, int stage)
{
     if (stage == 7)
     {
        if (IsPrime(num))
        {
           cout << "FOUND " << num << endl;
           return true;
        }
     }
     else
     {
         for (int c = 7; c > 0; c--)
         {       
             if (!digitUsed[c])
             {
                 if (!( (stage == 6) && ( (c == 2) || (c == 4) || (c == 5) || (c == 6) ) ))
                 {
                     digitUsed[c] = true;
                     
                     if (Perm(num * 10 + c, stage + 1))
                         return true;
                        
                     digitUsed[c] = false;
                 }
             }
         }
     }
         
     return false;
}

int main()
{       
    Perm(0,0);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    cout << "Time: " << duration.count();
    return 0;
}
