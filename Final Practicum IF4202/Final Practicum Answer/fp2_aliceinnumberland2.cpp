/*077's notes:
in the mystical land of numeria, the adventurer alice seeks to uncover the secrets hidden
within a collection of artifacts represented by an array of positive integers. alice discovers
that the concatenation of certain pairs of numbers in the array must be divisible by a given
number 𝑘 in order to unlock their power. the task is to count the number of ordered pairs in
the array that meet this condition. the input consists of the size of the array 𝑛, the given
number 𝑘, and the elements of the array. the output should be a single integer representing
the count of ordered pairs that satisfy the concatenation condition
fp2_alice in numberland*/

#include <bits/stdc++.h>
#define ll long long
#define forloop1 for(int i=0;i<n;i++)
#define forloop2 for(int j=0;j<n;j++)
using namespace std;

//function to count the number of ordered pairs that satisfy the concatenation condition
int orderpair(const vector<int>&array,int k){
    int hitung=0;
    int n=array.size();
    //iterate through each element in the array
    forloop1{
        //check pairs with elements after the current element
        forloop2{
            if(i!=j){
                ll con=array[i];//store the current element as the first part of the concatenation
                ll temp=array[j];//store the next element as the second part of the concatenation
                //concatenate the second part by multiplying it with powers of 10 and adding to the first part
                while(temp>0){
                    con*=10;
                    temp/=10;
                }
                con+=array[j];//add the second part to the first part
                //check if the concatenation is divisible by k
                if(con%k==0){
                    hitung++;//increment the count if the condition is satisfied
                }
            }
        }
    }
    return hitung;//return the final count of ordered pairs
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>array(n);
    //read the array elements from input
    forloop1{
        cin>>array[i];
    }
    int res=orderpair(array,k);//count the ordered pairs satisfying the condition
    cout<<res<<endl;//print the result
    return 0;
}
