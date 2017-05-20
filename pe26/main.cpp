#include <iostream>
#include <vector>

using namespace std;



int calcRecurringCycle(int denom)
{
    int         res;
    int         carry=10;
    vector<int> carries;
    
    /*
    // check that number is actually generating a periodic number  
    res=1000/denom;
    res=denom*res;
    
    // no need to consider this value
    if (res==1000)
        return 0;
    */

    do
    {
        int len=0;

        res=carry/denom;
        carry=(carry-(res*denom))*10;
        
        // if we found same value for carry we have a loop and can calculate its length
        for (vector<int>::reverse_iterator i=carries.rbegin();i!=carries.rend();i++,len++)
        {
            if (carry==*i)
                return len;
        }

        carries.push_back(carry);
        
    }
    while (carry!=0);

    // not periodic
    return 0;
}

int main()
{
    int max=0;
    int index=0;

    for (int i=2;i<1000;i++)
    {
        int count;

        cout << i << "\r\n";
        
        count=calcRecurringCycle(i);

        if (count>max)
        {
            index=i;
            max=count;
        }
    }

    cout << index;
    return 0;
}
