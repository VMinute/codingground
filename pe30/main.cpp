#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    const int exp=5;
    int max=pow(10,exp+1);
    int total=0;
    
    for (int i=2;i<=max;i++)
    {
        int val=i;
        int sum=0;
        
        while (val)
        {
           sum+=pow(val%10,exp);
           val/=10;
        }
        
        if (sum==i)
        {
            cout << i << "\r\n";
            total+=sum;
        }
    }
    
    cout << total;
}
