#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long sum=0;
    int  val=0;
    std::vector<int> digits;
    
    digits.push_back(1);
    
    for (int i=1;i<=1000;i++)
    {
        int carry=0;
        
        for (int j=0;j<digits.size();j++)
        {
            digits[j]*=2;
            digits[j]+=carry;
            carry=digits[j]/10;
            digits[j]=digits[j]%10;
        }
        
        if (carry)
        {
            digits.push_back(carry);
        }
    }
    
    cout << digits.size() << "\r\n";
    
    for (vector<int>::reverse_iterator d=digits.rbegin();d!=digits.rend();d++)
    {
        cout << *d;
        sum+=*d;
    }
        
    cout << "\r\n" << sum << "\r\n";
    
    return 0;
}

