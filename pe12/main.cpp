#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long value=0;
    long min=1;
    int  factorscount=0;
    
    // calculate smallest number with at least 500 divisors
    for (long i=1;i<500;i++)
        min*=i;
    
    for (long i=1;factorscount<=500;i++)
    {
        value+=i;

        if (i<min)
            continue;
            
        factorscount=0;
        
        long s=sqrt(value);
        
        for (long j=2;j<=s;j++)
        {
            if (value % j == 0)
            {
                factorscount+=2;
            }
        }
    }
    
    cout << value << "\r\n";
    return 0;
}

