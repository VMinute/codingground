#include <iostream>
#include <cmath>

#define DIGITS 3

using namespace std;

// largest palindrome that is the product of two 3 digits numbers

int main()
{
    int max=pow(10,DIGITS)-1;
    int min=pow(10,DIGITS-1);
    long largest=0;
    long loops=0;
    
    for (int n1=max;n1>=min;n1--)
    {
        // no chances to find bigger number
        if (n1<sqrt(largest))
            break;
            
        for (int n2=n1;n2>=min;n2--)
        {
            long product=n1*n2;
            int  digits=log10(product)+1;
            int  i;
            
            loops++;
            
            // no chances to find bigger number
            if (product<largest)
                break;
            
            //cout << product << "=";
            // compares digits
            for (i=0;i<digits/2;i++)
            {
                int digit1=(product % (long)pow(10,i+1))/(long)pow(10,i);
                int digit2=(product % (long)pow(10,digits-i))/(long)pow(10,digits-(i+1));
                
                //cout << digit1 << "-" << digit2 << " ";
                if (digit1!=digit2)
                    break;
            }   

            if (i==digits/2)
            {
                cout << product << " " << n1 << "x" << n2 << "\r\n";
                
                if (product>largest)
                    largest=product;
                else
                    break;
            }
        }
    }   
    
    cout << largest << " " << loops << "\r\n";
    return 0;
}

