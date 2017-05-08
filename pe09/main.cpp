#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    
    for (a=1;a<998;a++)
    {
        for (b=a;b<999-a;b++)
        {
            c=1000-(a+b);

            if (a*a+b*b==c*c)
            {
                cout << a << " " << b << " " << c << "\r\n";
                cout << a*b*c;
                return 0;                    
            }
        }
    }
    return 0;
}

