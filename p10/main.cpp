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
    long sum=2;
    
    // skip 1,2,3 and all even numbers
    for (long i=3;i<=2000000;i+=2)
    {
        if (isPrime(i))
            sum+=i;
    }
    cout << sum << "\r\n";
    return 0;
}

