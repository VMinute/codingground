#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
    long totscore=0;
    int pos=1;
    
    vector<string> names;
    ifstream namesfile("names.txt");
    
    string name;
    
    while (getline(namesfile,name,','))
    {
        // validate name (start and ends with quotes)
        if ((*(name.begin())!='\"')||((*name.rbegin())!='\"'))
            return 0;
            
        names.push_back(name.substr(1,name.length()-2));
    }          
    
    cout << names.size() << " names loaded.\r\n";
    
    sort(names.begin(),names.end());

    cout << names.size() << " names sorted.\r\n";
    
    for (vector<string>::iterator name=names.begin();name<names.end();name++)
    {
        long score=0;
        
        for (string::iterator c=(*name).begin();c<(*name).end();c++)
        {
            score+=(*c-'A')+1;            
        }
        score*=pos;
        totscore+=score;
        pos++;
    }
    
    cout << totscore << "\r\n";
    return 0;
}
