#include <iostream>
#include <chrono>
using namespace std;


auto start = chrono::high_resolution_clock::now();
int main()
{
    const int digits = 1000;
    const double ten = 10.0;
    int count = 1;
    double fibA = 1, fibB = 1, fibC = 2;
    for(int i = 3 ; ; i++)
    {
        fibC = fibA + fibB;
        fibA = fibB;
        fibB = fibC;
        if (fibC >= ten)
        {
            count++;
            fibA = fibA/ten;
            fibB = fibB/ten;
            fibC = fibC/ten;
        }
        if(count >= digits)
        {
            cout << i << "\n";
            break;
        }
    }
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time: " << duration.count() << " microseconds";
}