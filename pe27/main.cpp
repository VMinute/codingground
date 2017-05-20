#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    // 0 and negatives aren't primes
    if (n<1)
        return false;

    int s=sqrt((float)n);
    
    for (int i=2;i<=s;i++)
    {
        if ((n%i)==0)
            return false;
    }
    return true;
}

int calcPrimeSeriesLen(int a,int b)
{
    for (int n=0;;n++)
    {
        if (!isPrime((n*n)+(a*n)+b))
            return n;
    }
    return 0;
}

int main()
{
    int maxlen=0,maxa=0,maxb=0;

    for (int a=1;a<1000;a++)
    {
        for (int b=1;b<=1000;b++)
        {
            // b is added to the formula when n=0 reduces all the rest to 0
            if (!isPrime(b))
                continue;

            int len=calcPrimeSeriesLen(a,b);
            
            if (len>maxlen)
            {
                maxa=a;
                maxb=b;
                maxlen=len;
            }
            
            len=calcPrimeSeriesLen(a,-b);
            
            if (len>maxlen)
            {
                maxa=a;
                maxb=--b;
                maxlen=len;
            }
            
            len=calcPrimeSeriesLen(-a,b);
            
            if (len>maxlen)
            {
                maxa=-a;
                maxb=b;
                maxlen=len;
            }
            
            len=calcPrimeSeriesLen(-a,-b);
            
            if (len>maxlen)
            {
                maxa=-a;
                maxb=-b;
                maxlen=len;
            }
        }
        cout << ".";
    }
    cout << "\r\n" << maxa*maxb;
    return 0;
}
