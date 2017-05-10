#include <iostream>
#include <cmath>

using namespace std;

/*
just to check that lengths match
char* upto19[]={"zero",one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fithteen","seventeen","eighteen","nineteen"};
char* tents[]= {"ten", "twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety"};
char   hundred="hundred";
char*  hundredand="hundredand";
char*  onethousand="onethousand";
*/

int upto19len[]={ 0,3,3,5,4,4,3,5,4,4,3,6,6,8,8,8,9,8,8 };
int tentslen[]={ 3,6,6,5,5,5,7,6,6 };
int hundredlen=6;
int hundredandlen=11;
int onethousandlen=11;

int main()
{
    // start with one thousand (single occurrence)
    long totallen=onethousandlen;
    
    // hundred must be added 9 times (100,200...900)
    totallen+=(hundredlen*9);

    long onetoninelen=0;
    
    // and we must also add number from 1 to 9
    for (int i=1;i<=9;i++)
    {
        onetoninelen+=upto19len[i];
    }
    
    // "hundred and" must be added from 101 to 999, excluding houndreds
    totallen+=(hundredandlen*(900-9));
    
    // every number from 100 to 999 needs one,two etc. in front
    totallen+=onetoninelen*900;
        
    // now calculate the lenght of 0..99 that then must be added 10 times    
    long lessthan100=0;
    
    // 1 to 19
    for (int i=1;i<=19;i++)
        lessthan100+=upto19len[i];
        
    //21 to 99 exluding multiples of 10
    lessthan100+=onetoninelen*80;
    
    // 20 to 99 tents.
    for (int i=1;i<9;i++)
        lessthan100+=(tentslen[i])*10; //10

    totallen+=lessthan100*10;
    
    cout << totallen << "\r\n";
    return 0;
}

