//
//  timetest.cpp
//  
//
//  Created by Daivik Dinesh on 9/30/16.
//
//

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "CPUTimer.h"
#include "LinkedList.h"
#include "StackAr.h"
#include "CursorList.h"
#include "QueueAr.h"
#include "StackLi.h"
#include "vector.h"
#include "SkipList.h"

vector<CursorNode <int> > cursorSpace(500001);

int getChoice()
{
    cout << "      ADT MENU"<<endl;
    cout << "0. Quit"<<endl;
    cout << "1. LinkedList"<<endl;
    cout << "2. CursorList"<<endl;
    cout << "3. StackAr"<<endl;
    cout << "4. StackLi"<<endl;
    cout << "5. QueueAr"<<endl;
    cout << "6. SkipList"<<endl;
    cout << "Your choice >> ";
    cin >> choice;
    
    return choice;
}

void RunList(char* filename)
{
    List <int> li;
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.insert(num, li.zeroth());
        }
        
        else
        {
            li.remove(num);
        }
    }
}

void RunCursorList(char* filename)
{
    CursorList <int> li(cursorSpace);
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.insert(num, li.zeroth());
        }
        
        else
        {
            li.remove(num);
        }
    }
}

void RunStackAr(char* filename)
{
    StackAr <int> li(500001);
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.push(num);
        }
        
        else
        {
            li.pop();
        }
    }
}

void RunStackLi(char* filename)
{
    StackLi <int> li;
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.push(num);
        }
        
        else
        {
            li.pop();
        }
    }
}

void RunQueueAr(char* filename)
{
    Queue <int> li(500001);
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.enqueue(num);
        }
        
        else
        {
            li.dequeue();
        }
    }
}

void RunSkipList(char* filename)
{
    SkipList <int> li(0, 500001);
    
    char buff[256];
    char element;
    int num;
    ifstream fi(filename);
    fi.getline(buff, 256);
    
    while(fi.get(element))
    {
        fi>>buff;
        num = atoi(buff);
        fi.ignore(1);
        
        if( element == 'i')
        {
            li.insert(num);
        }
        
        else
        {
            li.deleteNode(num);
        }
    }
}


int main()
{
    char filename[256];
    int choice;
    CPUTimer ct;
    
    cout<< "Filename >> ";
    cin>>filename;
    cout<<endl;
    
    do
    {
        choice = getChoice();
        ct.reset();
        switch (choice)
        {
            case 1: RunList(filename); break;
            case 2: RunCursorList(filename); break;
            case 3: RunStackAr(filename); break;
            case 4: RunStackLi(filename); break;
            case 5: RunQueueAr(filename); break;
            case 6: RunSkipList(filename); break;
        }
        cout << "CPU time: " << ct.cur_CPUTime() << endl;
    } while(choice > 0);
}
