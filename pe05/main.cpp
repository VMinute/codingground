#include <iostream>
#include <cmath>

#define MAX_VALUE 20

// smallest number divisible from 1 to MAX_VALUE

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
    int*   values=new int[MAX_VALUE-1];
    long   retval=1;

    // at the beginning in values we have numbers 1..MAX_VALUE, then we will divide them by prime factors
    for (int i=1;i<=MAX_VALUE;i++)
        values[i-1]=i;
        
    for (int i=MAX_VALUE;i>2;i--)
    {
        // this will not change the result, skip it
        if (values[i-1]<=1)
            continue;
            
        // this is what remains of the original number    
        int n=values[i-1];
        
        // just for debug
        //cout << values[i-1] << " ";
        
        // multiply for final result
        retval*=values[i-1];
        
        // get prime factors, remove them from array (by setting value to 0) and divide all multiples in the array 
        while (!isPrime(n))
        {
            // limit for the loop (no need to consider factors in reverse order)
            int s=(int)sqrt(n);
            
            for (int j=2;j<=s;j++)
            {
                if (n % j != 0)
                 continue;
                
                // this is a prime factor, remove it from the array since we already considered it as part of current value
                values[j-1]=0;
                
                // divide all previous entries that contain that factor
                for (int x=2;x<i;x++)
                {
                    if (values[x-1] % j != 0)
                        continue;
                    
                    values[x-1]=values[x-1]/j;
                }
                
                // check if we have a prime now
                n=n/j;
                break;
            }
        }
        
        // remove current value (or its largest prime factor)
        values[n-1]=0;
        
        // divide all previous entries that contain that factor
        for (int x=2;x<i;x++)
        {
            if (values[x-1] % n != 0)
                continue;
            
            values[x-1]=values[x-1]/n;
        }    
    }
    
    cout << retval << "\r\n";
    return 0;
}