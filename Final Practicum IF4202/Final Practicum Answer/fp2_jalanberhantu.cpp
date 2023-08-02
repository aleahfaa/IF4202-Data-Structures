/*077's notes:
pokonya intinya tunjukin jln yg aman(lvl-nya)
n m:total input(n columns;m rows)
a b danger
output:the highest level of danger of the safest route
fp2_jalan berhantu (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

/*structure to represent a road*/
struct road{
    int place;//destination place
    int danger;//danger level of the road
    road(int p,int d):place(p),danger(d){}
};

/*find the route with the highest danger level*/
int froute(int n,int m,vector<vector<road>>&graph){//find route
    //store the maximum danger level for each place
    vector<int>dmax(n+1,numeric_limits<int>::max());//danger maximum
    dmax[1]=0;//start place has a danger level of 0
    //priority queue to process roads in ascending order of danger level
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>priorq;
    priorq.push({0,1});//push the start place with danger level 0 into the priority queue
    while(!priorq.empty()){
        int danger=priorq.top().first;//get the minimum danger level
        int place=priorq.top().second;//get the corresponding place
        priorq.pop();
        if(danger>dmax[place]){
            continue;//skip the place if its danger level is already higher than the stored maximum
        }
        for(const road&road:graph[place]){
            int next=road.place;//get the destination place of the road
            //calculate the maximum danger level between the current place and the destination place
            int nextd=max(danger,road.danger);//next danger
            if(nextd<dmax[next]){
                dmax[next]=nextd;//update the maximum danger level for the destination place
                priorq.push({nextd,next});//add the destination place with its new danger level into the priority queue
            }
        }
    }
    return dmax[n];//return the maximum danger level of the destination place
}

/*read the graph representation from input*/
void rgraph(vector<vector<road>>&graph,int m){//read graph
    for (int i=1;i<=m;++i) {
        int a,b,c;
        cin>>a>>b>>c;
        //add the road from place 'a' to 'b' and its corresponding danger level to the graph
        graph[a].push_back(road(b,c));
        graph[b].push_back(road(a,c));
    }
}

int main(){
    ios_base::sync_with_stdio(false);//optimizes input/output operations
    cin.tie(nullptr);//optimizes input/output operations
    int n,m;
    cin>>n>>m;//read the total number of places and roads
    vector<vector<road>>graph(n+1);//create a graph representation using an adjacency list
    rgraph(graph,m);//read the graph representation from input
    int dang=froute(n,m,graph);//find the highest danger level along the safest route
    cout<<dang<<endl;//output the result
    return 0;
}
