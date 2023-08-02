/*077's notes:
();[];{}
pokonya intinya gaboleh selingkuh dari pasangannya
if setia,print valdi
if selingkuh,print unvaldi
liburan ersya cpp mode*/

#include<bits/stdc++.h>
using namespace std;

bool van(const string& s){
    stack<char>stek;
    for(char inp:s){
        if (inp=='('||inp=='['||inp=='{') {
            stek.push(inp);
        }else if(inp==')'||inp==']'||inp=='}'){
            if(stek.empty()){
                return false;
            }
            char top=stek.top();
            stek.pop();
            if ((inp==')'&&top!='(')||(inp==']'&&top!='[')||(inp=='}'&&top!='{')){
                return false;
            }
        }
    }
    return stek.empty();
}

int main(){
    string s;
    cout<<s;
    getline(cin,s);
    if(van(s)){
        cout<<"valdi"<<endl;
    }else{
        cout<<"unvaldi"<<endl;
    }
    return 0;
}
