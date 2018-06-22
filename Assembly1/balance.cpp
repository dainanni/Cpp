//
//  balance.cpp
//  
//
//  Created by Daivik Dinesh on 10/1/16.
//
//

#include <iostream>
#include <fstream>
#include "StackLi.h"
#include <cstdlib>
#include <cstring>


int main(int argc, char** argv)
{
    StackLi <char> st;
    StackLi <int> lnum;
    bool isComment = false;
    
    int ln = 1;
    
    ifstream fi(argv[1]);
    char buffer[256];
    
    
    while(fi.getline(buff, 256))
    {
        for(int i =0; i < strlen(buff); i++)
        {
            if( buff[i] == '/' && buff[i+1] == '*')
            {
                st.push('/');
                lnum.push(ln);
                isComment = true;
            }
            
            if( isComment && buff[i] == '*')
            {
                if( i+1 < strlen(buff) && buff[i+1] == '/')
                {
                    st.pop();
                    lnum.pop();
                    isComment = false;
                }
                
            }
            
            if( !isComment)
            {
                if( buff[i] == '(' || buff[i] == '[' || buff[i] == '{')
                {
                    st.push(buff[i]);
                    lnum.push(ln);
                }
                
                else if( buff[i] == '*' && i+1 < strlen(buff) && buff[i+1] == '/')
                {
                    cout<< "Unmatched */ on line #"<<ln<<endl;
                    return 0;
                }
                
                else if(buff[i] == ')' || buff[i] == ']' || buff[i] == '}')
                {
                    if(st.isEmpty())
                    {
                        cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                        return 0;
                    }
                    else
                    {
                        if(buff[i] == ')')
                        {
                            if(st.top() == '(')
                            {
                              st.pop();
                              lnum.pop();
                            }
                            
                            else
                            {
                                char temp = st.topAndPop();
                                
                                if(st.isEmpty())
                                {
                                    cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                    return 0;
                                }
                                
                                else
                                {
                                    if(st.top() == '(')
                                    {
                                        cout<<"Unmatched "<<temp<<" on line #"<<lnum.top()<<endl;
                                        return 0;
                                    }
                                    
                                    else
                                    {
                                        cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                        return 0;
                                    }
                                }
                            }
                            
                            if(buff[i] == '}')
                            {
                                if(st.top() == '{')
                                {
                                    st.pop();
                                    lnum.pop();
                                }
                                
                                else
                                {
                                    char temp = st.topAndPop();
                                    
                                    if(st.isEmpty())
                                    {
                                        cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                        return 0;
                                    }
                                    
                                    else
                                    {
                                        if(st.top() == '{')
                                        {
                                            cout<<"Unmatched "<<temp<<" on line #"<<lnum.top()<<endl;
                                            return 0;
                                        }
                                        
                                        else
                                        {
                                            cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                            return 0;
                                        }
                                    }
                                }

                            
                        }
                            
                            if(buff[i] == ']')
                            {
                                if(st.top() == '[')
                                {
                                    st.pop();
                                    lnum.pop();
                                }
                                
                                else
                                {
                                    char temp = st.topAndPop();
                                    
                                    if(st.isEmpty())
                                    {
                                        cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                        return 0;
                                    }
                                    
                                    else
                                    {
                                        if(st.top() == '[')
                                        {
                                            cout<<"Unmatched "<<temp<<" on line #"<<lnum.top()<<endl;
                                            return 0;
                                        }
                                        
                                        else
                                        {
                                            cout<<"Unmatched "<<buff[i]<<" on line #"<<ln<<endl;
                                            return 0;
                                        }
                                    }
                                }

                    }
                }
            }
        }

     ln++;
    }
            
  if(!st.isEmpty())
  {
      if(st.top() == '/')
      {
          cout<<"Unmatched /* on line #"<<lnum.top()<<endl;
          return 0;
      }
      
      else
      {
          cout<<"Unmatched "<<st.top()<<" on line #"<<lnum.top()<<endl;
          return 0;
      }
    
  }
  
  else
  {
      cout<<"OK"<<endl;
  }
}

