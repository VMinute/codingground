#include <iostream>

using namespace std;

bool isPrime(long num)
{
    long m=(long)sqrt(num);
    
    if (m*m==num)
        return false;
        
    for (long i=2;i<m;i++)
    {
        if (num%i==0)
            return false;
    }
    return true;
}

long nextPrime(long num)
{
    for (;isprime(num);num++)
        ;
    return num;
}

int main()
{
   long value=600851475143;
   long lastfactor=0;
   
   for (factor=2;value==factor;factor=nextPrime(factor))
   {
       if (value%factor=0)
       {
           printf("factor: %d\r\n");
           lastfactor=factor;
           value/=factor;
       }
   }

   
   return 0;
}