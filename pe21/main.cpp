#include <iostream>
#include <cmath>

using namespace std;

int sumOfDivisors(int num)
{
    int sum=1;
    int max=sqrt(num);
    
    for (int i=2;i<max;i++)
    {
        if ((num % i)==0)
            sum+=i;
    }
    
    return sum;
}

int main()
{
    int tot=0;
    
    for (int i=1;i<10000;i++)
    {
        int sum1=sumOfDivisors(i);
        
        // we already calculated it
        if (sum1<=i)  
            continue;
    
        int sum2=sumOfDivisors(sum1);
        
        if (i!=sum2)
            continue;
            
        if (sum2>10000)
            continue;
            
        cout << i << "-" << sum1 << "\r\n";
        
        tot+=i+sum1;
    }
    
    cout << tot;
    return 0;
}
