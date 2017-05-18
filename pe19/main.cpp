#include <iostream>

using namespace std;

int months[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int firstofthemonth[12];
int firstofthemonthleap[12];

// leap years are multiples of 4, not 100 but 400
bool isLeap(int year)
{
    if (year % 4)
        return false;
        
    if (year % 100)
        return true;
        
    if (year % 400)
        return false;
        
    return true;
}

int main()
{
    // 0 = monday
    int firstday=0;
    int count=0;
    
    firstofthemonth[0]=0;
    firstofthemonthleap[0]=0;
    
    // calculate day number for 1st of the month
    for (int i=1;i<12;i++)
    {
       firstofthemonth[i]=firstofthemonth[i-1]+months[i-1];
       firstofthemonthleap[i]=firstofthemonth[i]+((i>=2)?1:0);
    }
    
    // calculate difference between 1st of year to 1st of each month
    for (int i=1;i<12;i++)
    {
       firstofthemonth[i]=firstofthemonth[i]%7;
       firstofthemonthleap[i]=firstofthemonthleap[i]%7;
    }
    
    
    for (int year=1900;year<=2000;year++)
    {
        if (year>1900)
        {
            int firstsun=6-firstday;
            int* firstarray=(isLeap(year)?firstofthemonthleap:firstofthemonth);
            
            for (int i=0;i<12;i++)
            {
                // not a sunday
                if (firstarray[i] == firstsun)
                {    
                    count++;
                    cout << "1/" << i+1 << "/" << year << "\r\n";
                }    
            }
        }
        
        if (isLeap(year))
            firstday=(firstday+2)%7;
        else
            firstday=(firstday+1)%7;
        
    }
    
    cout << count << "\r\n";
    
    return 0;
}
