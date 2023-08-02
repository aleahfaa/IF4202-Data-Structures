/*077's notes:
input:
m,n as the list size
first list (m),separated by space
second list(n),separated by space
output:
the total of two list
fp_player muak linked list (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

//function to add two lists represented as vectors of integers
string add(const vector<int>& listm,const vector<int>& listn){
    string result;//variable to store the result
    int c=0;//variable to store the carry value
    int i=listm.size()-1;//index for listm
    int j=listn.size()-1;//index for listn
    //iterate over the lists until all digits are processed and there is no carry left
    while(i>=0||j>=0||c>0){
        int tot=c;
        //add the corresponding digits from list1 and list2 if they exist
        if(i>=0){
            tot+=listm[i];
            i--;
        }
        if(j>=0){
            tot+=listn[j];
            j--;
        }
        //append the unit digit of the sum to the result
        result.push_back(tot%10+'0');
        //calculate the carry for the next iteration
        c=tot/10;
    }
    //reverse the result to obtain the correct order
    reverse(result.begin(),result.end());
    return result;
}

int main() {
    int m,n;
    cin>>m>>n;
    //create vectors to store the input lists
    vector<int>listm(m);
    vector<int>listn(n);
    //read the elements of listm from input
    for(int i=0;i<m;i++){
        cin>>listm[i];
    }
    //read the elements of listn from input
    for(int i=0;i<n;i++){
        cin>>listn[i];
    }
    //compute the sum of the lists using the addLists function
    string tot=add(listm,listn);
    //print the result
    cout<<tot<<endl;
    return 0;
}