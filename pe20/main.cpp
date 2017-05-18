#include <iostream>
#include <vector>

using namespace std;


int main()
{
    vector<int> digits;
    
    digits.push_back(1);
    
    
    for (int i=2;i<=100;i++)
    {
        int carry=0;
        
        for (vector<int>::iterator d=digits.begin();d!=digits.end();d++)
        {
            int val=(*d)*i;
            
            val+=carry;
            *d=(val%10);
            carry=val/10;
        }
        
        while (carry)
        {
            digits.push_back(carry%10);
            carry/=10;
        }
    }
    
    int sum=0;

    for (vector<int>::reverse_iterator d=digits.rbegin();d!=digits.rend();d++)
    {
        cout << *d;
        sum+=*d;
    }
    
    cout << "\r\n" << sum;
    return 0;
}
