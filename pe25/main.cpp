// Example program
#include <iostream>
#include <vector>

using namespace std;

// we take for granted that v2 > v1
void sum(vector<int>& v1, vector<int>& v2)
{
    int carry=0;
    vector<int>::iterator i1=v1.begin();
    vector<int>::iterator i2=v2.begin();
    
    /*
    for (vector<int>::reverse_iterator i=v1.rbegin();i!=v1.rend();i++)
        cout << *i ;
        
    cout << "-";

    for (vector<int>::reverse_iterator i=v2.rbegin();i!=v2.rend();i++)
        cout << *i ;
        
    cout << "=";
    */

    for (;i1!=v1.end();i1++,i2++)
    {
        int val=carry+(*i1)+(*i2);
        
        *i1=*i2;
        *i2=val%10;
        carry=val/10;
    }
    
    for (;i2!=v2.end();i2++)
    {
        v1.push_back(*i2);
        *i2=(*i2+carry) % 10;
        carry/=10;
    }
    
    while (carry)
    {
        v2.push_back(carry % 10);
        carry/=10;
    }    

    /*
    for (vector<int>::reverse_iterator i=v2.rbegin();i!=v2.rend();i++)
        cout << *i ;
        
    cout << "\r\n";
    */
}


int main()
{
    vector<int> n1,n2;
    
    n1.push_back(1);
    n2.push_back(1);
    
    int index=1;
    
    for (index=1;n2.size()<1000;index++)
    {
        sum(n1,n2);
    }
        
    cout << (++index)  << "\r\n";
    return 0;
}
