#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    int sqroot=(int)sqrt(num);
    
    for (int i=2;i<=sqroot;i++)
    {
        if (num%i == 0)
            return false;
    }
    return true;
}

int main()
{
    long lastprime;
    
    for (long num=2,primecount=0;primecount<=10000;num++)
    {
        if (isPrime(num))
        {
            primecount++;
            lastprime=num;
        }
    }
    
    cout << lastprime << "\r\n";
    return 0;
}

