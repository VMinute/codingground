// Example program
#include <iostream>
#include <cmath>

using namespace std;

// check if a number is a perfect power
bool isPow(int n,int& v,int& pow)
{
    int s=sqrt((float)n);
    
    // finds minimum divider
    for (int d=2;d<=s;d++)
    {
        pow=0;
        v=n;

        while (v%d==0)
        {
            v=v/d;
            pow++;
        }
        
        if (v==1)
        {
            v=d;
            return true;
        }
    }
    return false;
}

int main()
{
    const int maxpow=100;
    int distincts=(maxpow-1)*(maxpow-1);
    
    for (int i=2;i<=maxpow;i++) 
    {
        int v,pow;
        
        if (isPow(i,v,pow))
        {
            // we should remove numbers up to v`100/pow
            distincts-=(maxpow/pow)-1;
            pow/=2;
        }
    }
    
    cout << distincts;
    
}
