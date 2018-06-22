//
//  decipher.cpp
//  decipher
//
//  Created by Daivik Dinesh on 3/1/16.
//
//

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

class Check
{
    int shift;
    int like;
    
public:
    
    check();
    
    void setVal(int s, int l)
    {
        shift = s;
        like = l;
    }
    
    int getShift()
    {
        return shift;
    }
    
    bool operator<(Check &check)
    {
        return (like < check.like);
    }
    
    
};

void likelihood(vector <int> *f, vector <int> *e, vector <Check> *l)
{

    for(int j = 0; j < 26; j++)
    {
        int total = 0;
        
        for(int i = 0; i < 26; i++)
        {
            total += f->at(i) * e->at( ( i + j ) % 26 );
        }
    
        l->at(j).setVal(j, total);
        
    }
}

void frequency(vector <int> *f, vector <int> *e, string temp )
{
    int j;
    
    ifstream freq("frequencies");
    
    for(int i =0; i<26; i++)
    {
        freq >> j;
        f->push_back(j);
    }
    
    ifstream fre("argv[1]");
    
    stringstream s;
    
    s >> fre.rdbuf();
    
    temp = s.str();
    
    for(char x = 'A'; x <= 'Z'; x++)
    {
        e->push_back(count(temp.begin(), temp.end(), x) +
          count(temp.begin(), temp.end(), x + 'a' - 'A'));
    }
  
}

void print(string &temp, vector <Check> *l, int x)
{
    
    for(int y = 0; y < temp.length(); y++)
    {
        if( isalpha(string.at(y)))
        {
            if(string.at(y) >= 'a' && string.at(y) <= 'z')
                cout << (char)('a' + ((string.at(y) - 'a' + (26 - x)) % 26)) << endl;
            
            if(string.at(y) >= 'A' && string.at(y) <= 'Z')
                cout << (char)('A' + ((string.at(y) - 'A' + (26 - x)) % 26)) << endl;
                //string.at(y) = 'A' + ((string.at(y) - 'A' + (26 - x)) % 26);
        }
    }
    
    
}


int main( int argc, char *argv[])
{
    vector <int> f;
    vector <int> e;
    vector <Check> l(26);
    string temp;
    
    frequency(&f, &e, temp);
    likelihood(&f, &e, &l);
    
    sort(l.rbegin(), l.rend());
    
    for(int k = 0; k <= 6; k++)
    {
        cout<< "Deciphered message version #" << k+1 << endl;
        print( temp, l->at(k).getShift());
        cout << temp << endl;
        print( temp, (l->at(k).getShift() * (-1)))
    }
    
    return 0;
}