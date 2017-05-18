#include <iostream>
#include <cmath>
#include <vector>
#include <unordered_set>

using namespace std;

int sumOfDivisors(int num)
{
    int sum=1;
    int max=num/2;
    
    for (int i=2;i<=max;i++)
    {
        if ((num % i)==0)
            sum+=i;
    }
    
    return sum;
}

int main()
{
    const int maxval=28123;
    long  sum=0;

    vector<int> abundants;

    // stores all abundant numbers in the range 
    for (int i=1;i<=maxval;i++)
    {               
        if (sumOfDivisors(i)>i)
            abundants.push_back(i);
    }
    
    cout << abundants.size() << "\r\n";
    
    unordered_set<int> abundantssums;
    
    // calculate all possible sums of two abundant numbers and store them in a set
    for (vector<int>::iterator a1=abundants.begin();a1<abundants.end();a1++)
    {
        for (vector<int>::iterator a2=a1;a2<abundants.end();a2++)
        {
            if ((*a1)+(*a2)>maxval)
                break;
                
            abundantssums.insert(*a1+*a2);
        }
    }   
        
    for (int i=1;i<=maxval;i++)
    {               
        if (abundantssums.find(i)==abundantssums.end())
            sum+=i;
    }
    
    cout << sum << "\r\n";
    return 0;
}
