#include <iostream>

using namespace std;

int main()
{
    int sum=1;
    int val=1;
    
    for (int side=3;side<=1001;side+=2)
    {
        for (int i=0;i<4;i++)
        {
            val+=(side-1);
            sum+=val;
        }
    }
    
    cout << sum;
}
