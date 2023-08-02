/*077's notes:
input:
total testcase
total items
item's price
output:
total leftover item;cuz buyer cant take items with the same prices
fp2_made in haven (cpp mode)*/
//https://www.its.ac.id/informatika/domjudge/public/problems/347/text

#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*function to get the difference between the counts of two most frequent numbers*/
int gdiff(unordered_map<ll,ll>&count){//get difference
    auto n1=count.begin();
    auto n2=next(n1);
    return abs(n1->second-n2->second);
}

/*function to find a possible dominator in the count map*/
int gdom(unordered_map<ll,ll>&count,ll ncount){//count:numcount;ncount:numbercount
    for(auto ht:count){
        if(ht.second>(ncount/2)){//if the count of a number is greater than half the total count, it is a possible dominator
            return ht.first;//return the number as the dominator
        }
    }
    return 0;//return 0 if no dominator is found
}

/*function to solve a query given the item count*/
int solque(ll icount){//solve query;item count
    unordered_map<ll,ll>count;//map to store the counts of each number
    ll ncount=0;//total count of numbers
    for(int i=1;i<=icount;i++){
        ll inp;
        cin>>inp;
        count[inp]+=1;//increment the count of the input number
        ncount+=1;//increment the total count
    }
    if(count.size()==1){//if there is only one distinct number
        return ncount;//return the total count
    }else if(count.size()==2){//if there are only two distinct numbers
        return gdiff(count);//return the difference in their counts
    }else{
        ll dom=gdom(count,ncount);//find a possible dominator in the count map
        if(dom!=0){//if a dominator is found
            return count[dom]-(ncount-count[dom]);//return the difference between its count and the count of other numbers
        }else{//if no dominator is found
            return ncount%2;//return the parity of the total count
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll queries;
    cin>>queries;
    for(int i=1;i<=queries;i++){
        ll icount;
        cin>>icount;
        ll res=solque(icount);//solve the query for the given item count
        cout<<res<<"\n";//output the result
    }
    return 0;
}
