// Example program
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{   
    const int max=10;
    const int pos=1000000;
    vector<int> digits;
    
    for (int i=0;i<max;i++)
        digits.push_back(i);

    for (int count=1;count<pos;count++)
        next_permutation(digits.begin(),digits.end());
    
    for (vector<int>::iterator d=digits.begin();d<digits.end();d++)
        cout << *d;                
}
