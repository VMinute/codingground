#include <iostream>
#include <cmath>

#define MAX_VALUE 10

// smallest number divisible from 1 to MAX_VALUE

using namespace std;

bool isPrime(int num)
{
    int sqroot=(int)sqrt(num);
    
    for (int i=2;i<=sqroot;i++)
    {
        if (num%i != 0)
            return false;
    }
    return true;
}

int main()
{
    int*   values=new int[MAX_VALUE-1];
    int    retval;

    for (int i=1;i<=MAX_VALUE;i++)
        values[i-1]=i;
        
        cout << "dummy";
        
    for (int i=MAX_VALUE;i>1;i--)
    {
        if (values[i-1]==0)
            continue;
            
        int n=i;
        
        cout << i << " ";
        
        retval*=i;
        
        while (!isPrime(n))
        {
            int s=(int)sqrt(n);
            
            for (int j=2;j<=s;j++)
            {
                if (n % j != 0)
                 continue;
                
                values[j-1]=0;
                n=n/j;
                break;
            }
        }
        
        values[n-1]=0;
    }
    
    for (int i=1;i<=MAX_VALUE;i++)
    {
        cout << values[i-1] << " ";
        if (values[i-1])
            retval*=i;
    }
    cout << retval << "\r\n";
    return 0;
}