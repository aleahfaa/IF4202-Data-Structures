/*077's notes:
input:
{},[],(),<>
based on order
{} level 1
[] level 2
() level 3
<> level 4
output:
if the conditions fullfilled print "valid",otherwise print "invalid"
eas_its your classic bracket!*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <string>
#define ce1048 cout<<"Valid"<<endl
#define str string
#define l left
#define forloop for(int i=0;i<inp.length();i++)
using namespace std;

bool van(char b,str loc){
    if(loc=="l"){
        return b=='<'||b=='('||b=='[';
    }else{
        return b=='>'||b==')'||b==']';
    }
}

int main(){
    str inp;
    cin>>inp;
    stack<char>st;
    forloop{
        if(inp.length()%2!=0){
            cout<<"Invalid"<<endl;
            return 0;
        }else if(inp.length()>2){
            if((inp[i]=='{'&&i==0)||(inp[i]=='['&&i==1)||(inp[i]=='('&&i==2)||(inp[i]=='<'&&i==3)){
                st.push(inp[i]);
            }else if(inp[i]=='}'||inp[i]==']'||inp[i]==')'||inp[i]=='>'){
                if(st.size()==0){
                    cout<<"Invalid"<<endl;
                    return 0;
                }
                char top=st.top();
                st.pop();
                if((inp[i]=='}'&&top!='{')||(inp[i]==']'&&top!='[')||(inp[i]==')'&&top!='(')||(inp[i]=='>'&&top!='<')){
                    cout<<"Invalid"<<endl;
                    return 0;
                }
            }
        }
    }
    ce1048;
    return 0;
}