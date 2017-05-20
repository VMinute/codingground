// Example program
#include <iostream>
#include <vector>

using namespace std;

int countCombinations(vector<int>& coins,int index,int amount)
{
    int res=0;
    int count=0;
    int value=coins[index];
    int maxnum=amount/value;
    
    for (int i=0;i<=maxnum;i++)
    {
        res=amount-(value*i);
        
        if (res==0)
        {
            count++;
        }
        else
        {
            if (index>0)
                count+=countCombinations(coins,index-1,res);
        }
    }
    return count;
}

int main()
{
    const int targetvalue=200;
    vector<int> coins;
    
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    coins.push_back(10);
    coins.push_back(20);
    coins.push_back(50);
    coins.push_back(100);
    coins.push_back(200);

    cout << countCombinations(coins,coins.size()-1,targetvalue);    
}
