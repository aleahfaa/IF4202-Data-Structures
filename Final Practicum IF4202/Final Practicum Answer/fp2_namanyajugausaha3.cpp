/*077's notes:
input:
dungeon total
dungeon1 dungeon2 (related to each other)
"-1 -1" means stop
output:
steps to go back to the first dungeon (separate by enter)
if cant go back,print the step then "gak bisa pulang mamah"
fp2_namanya juga usaha (cpp mode)*/
//https://www.its.ac.id/informatika/domjudge/public/problems/348/text

#include <bits/stdc++.h>
using namespace std;

void pedge(vector<vector<int>>& adj,int start,int destination){
    adj[start].push_back(destination);
}

int bfs(const vector<vector<int>>& adj,int start,int n){
    vector<bool>visited(n,false);
    vector<int>steps(n,-1);
    queue<int>q;
    q.push(start);
    visited[start]=true;
    steps[start]=0;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int next:adj[cur]){
            if(!visited[next]){
                q.push(next);
                visited[next]=true;
                steps[next]=steps[cur]+1;
            } else if(next==start){
                return steps[cur]+1;
            }
        }
    }
    return -1;
}

int main() {
    int count;
    cin>>count;
    vector<vector<int>>adj(count);
    int start,destination;
    cin>>start>>destination;
    while(start!=-1&&destination!=-1){
        pedge(adj,start,destination);
        cin>>start>>destination;
    }
    for(int counter=0;counter<count;counter++){
        int steps=bfs(adj,counter,count);
        if (steps==-1) {
            cout<<"gak bisa pulang mamah"<<endl;
        }else{
            cout<<steps<<endl;
        }
    }
    return 0;
}