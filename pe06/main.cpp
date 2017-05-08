#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    long sumofsquares=0;
    long squareofsum=0;
    
    for (long i=1;i<=100;i++)
    {
        squareofsum+=i;
        sumofsquares+=i*i;
    }
    squareofsum*=squareofsum;
    
    cout << squareofsum-sumofsquares << "\r\n";
    return 0;
}

