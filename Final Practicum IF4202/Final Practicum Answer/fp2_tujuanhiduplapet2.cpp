/*077's notes:
input:
node edge
a b (edge total)
output:
loc total
a route to the peak
or death "RIP LAPET 2023"
fp2_tujuan hidup lapet*/
//gw aja gatau tujuan hidup gw,knp disuruh cari tujuan hidup lapet

#include <bits/stdc++.h>
#define max 100000
using namespace std;

vector<int>graph[max];
bool visited[max];
int parent[max];

vector<int>fpath(int start,int destination){
    vector<int>path;
    int loc=destination;
    while(loc!=-1){
        path.push_back(loc);
        loc=parent[loc];
    }
    //path.push_back(start);
    reverse(path.begin(),path.end());
    return path;
}

vector<int>bfs(int start,int destination){
    queue<int>q;
    q.push(start);
    visited[start]=true;
    parent[start]=-1;
    while(!q.empty()){
        int loc=q.front();
        q.pop();
        if(loc==destination){
            return fpath(start,destination);
        }
        for(int neighbor:graph[loc]){
        //for(auto neighbor:graph[loc]){
            if(!visited[neighbor]){
                visited[neighbor]=true;
                parent[neighbor]=loc;
                q.push(neighbor);
            }
        }
    }
    return {};
}

int main(){
    int n,e;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int start=1;
    int destination=n;
    vector<int>path=bfs(start,destination);
    if(path.empty()){
        cout<<"RIP LAPET 2023"<<endl;//semoga khusnul khotimah
    }else{
        //int res=path.size();
        //cout<<res<<endl;
        cout<<path.size()<<endl;
        //for(int i=0;i<path.size();i++){
        //for(int i=0;i<res;i++){
        for(int loc:path){
            //cout<<path[i]<<" ";
            cout<<loc<<" ";
        }
        cout<<endl;
    }
    return 0;
}