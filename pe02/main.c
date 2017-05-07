#include <stdio.h>

int main()
{
    int i;
    int prev=1;
    int tmp;
    long sum=0;
    
    for (i=2;i<=4000000;tmp=prev,prev=i,i+=tmp)
    {
        if (i%2==0)
            sum+=i;
        printf("%d ",i);    
    }
    
    printf("Sum is: %d\r\n",sum);
    return 0;
}

