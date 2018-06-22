//
//  bags.cpp
//  
//
//  Created by Daivik Dinesh on 10/1/16.
//
//

#include "StackLi.h"
#include "QueueAr.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

int main( int argc, char** argv)
{
    ifstream fi(argv[1]);
    
    StackLi <Queue> stq;
    Queue <short> q(atoi(argv[2]));
    short temp;
    
    while(fi>>temp)
    {
        q.enqueue(temp);
        
        if(q.isFull())
        {
            stq.push(q);
            q.makeEmpty();
        }
        
    }
    
    stq.push(q);
    q.makeEmpty();

    
    while(!stq.isEmpty())
    {
        q = stq.topAndPop();
        
        while(!q.isEmpty())
        {
            cout<<q.dequeue()<<" ";
        }
    }
    
    cout<<endl;
    
    return 0;
}
