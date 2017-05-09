#include <iostream>

using namespace std;

long CollatzSeqLength(long num)
{
    long count;
    
    for (count=1;num!=1;count++)
    {
        if (num % 2)
            num=3*num+1;
        else
            num/=2;
            
        //cout << num << " ";
    }
    
    return count;
}

int main()
{
    long maxlen=0;
    long maxval=0;
    
    for (long i=3;i<1000000;i++)
    {
        long len=CollatzSeqLength(i);
        
        if (len>maxlen)
        {
            maxlen=len;
            maxval=i;
        }
    }

    cout << maxval << " " << maxlen << "\r\n";
   
   return 0;
}

