#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int num)
{
    int sqroot=(int)sqrt(num);
    
    // all even numbers that are not 2 aren't prime, this will allow 
    // us to reduce iterations by 50%
    if (num % 2==0)
        return (num==2);
    
    for (int i=3;i<=sqroot;i+=2)
    {
        if (num%i == 0)
            return false;
    }
    return true;
}

int main()
{
    long lastprime;
    
    // primes after 2 can't be even numbers
    for (long num=3,primecount=1;primecount<=10000;num+=2)
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

