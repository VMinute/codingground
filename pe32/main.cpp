// Example program
#include <iostream>
#include <cmath>

using namespace std;

bool uniqueDigits(int n)
{
    int a=n;
    
    while (a>0)
    {
        int da=a%10;
        int b=a/10;
        
        // we need digits 1-9
        if (da==0)
            return false;
                    
        while (b>0)
        {
            int db=b%10;
        
            if (db==0)
                return false;
            
            
            if (da==db)
                return false;
            
            b/=10;
        }
        a/=10;
    }
    return true;
}

bool distinctDigits(int a,int b)
{
    while (a>0)
    {
        int da=a%10;
        int tb=b;
        
        // we need digits 1-9
        if (da==0)
            return false;
            
        while (tb>0)
        {
            int db=tb%10;
        
            if (db==0)
                return false;
            
            if (da==db)
                return false;
            
            tb/=10;
        }
        a/=10;
    }
    return true;
}

int countDigits(int n)
{
    int count=1;
    
    while ((n=n/10)>0)
        count++;
        
    return count;
}

int main()
{
    int count=0;
    long sum=0;
    
    // we have max 9 digits, so we can consider 
    for (int a=1;a<=9999;a++)
    {
        if (!uniqueDigits(a))
            continue;
            
        for (int b=a;b<=9999;b++)
        {
            if (!uniqueDigits(b))
                continue;
            // if b contains digits that are also in a, we can skip the product
            if (!distinctDigits(a,b))
                continue;
                
            int prod=a*b;
            
            if (!uniqueDigits(prod))
                continue;
            
            if ((distinctDigits(a,prod))&&(distinctDigits(b,prod)))
            {
                // we used all 9 digits?
                if (countDigits(a)+countDigits(b)+countDigits(prod)==9)
                {
                    cout << a << "*" << b << "=" << prod << "\r\n";
                    count++;
                    sum+=prod;
                }
            }
        }
    }
    
    cout << sum;
}
