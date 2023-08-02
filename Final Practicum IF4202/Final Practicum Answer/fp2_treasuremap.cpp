/*077's notes:
input:
size of map;total treasures
location of treasure(the coordinate)
[h,v or x,y coordinate]
output:
the treasure map based on the input
fp2_making a treasure map (cpp mode)*/
//https://www.its.ac.id/informatika/domjudge/public/problems/367/text

#include <bits/stdc++.h>
#define sz size
using namespace std;

/*function to recursively fill the map with appropriate numbers*/
void isi(vector<vector<int>>&map,int x,int y,int num){
    int n=map.sz();
    //check if the current position is within the map and not already filled with a higher number
    if(x>=0&&x<n&&y>=0&&y<n&&(map[x][y]==0||map[x][y]>num)&&num<=4){
        map[x][y]=num;
        //recursive calls to fill the surrounding cells
        isi(map,x,y+1,num+1);//east
        isi(map,x,y-1,num+1);//west
        isi(map,x-1,y,num+1);//north
        isi(map,x+1,y,num+1);//south
    }
}

/*function to mark the surrounding cells of a treasure with appropriate numbers*/
void tanda(int sz,int x,int y,vector<vector<int>>&map){//x,y:current cell coordinate
    for(int rad=2;rad<=4;rad++){//distance/radius
        for(int radx=-rad+1;radx<=rad-1;radx++){
            int nx=x-1+radx;//new coordinate x
            int ny1=y-1-rad+1+abs(radx);//new coordinate y1(first cell)
            int ny2=y-1+rad-1-abs(radx);//new coordinate y2(second cell)
            //check if the new coordinates are within the map and mark the cells accordingly
            if(nx>=0&&nx<sz){
                if(ny1>=0&&ny1<sz&&(map[nx][ny1]==0||map[nx][ny1]>=rad)){
                    map[nx][ny1]=rad;
                }
                if(ny2>=0&&ny2<sz&&(map[nx][ny2]==0||map[nx][ny2]>=rad)){
                    map[nx][ny2]=rad;
                }
            }
        }
    }
}

/*main function*/
int main(){
    int n,m;
    cin>>n>>m;
    //create an n x n map initialized with zeros
    vector<vector<int>>map(n,vector<int>(n,0));
    //read the coordinates of the treasures and mark the map accordingly
    for(int i=0;i<m;i++){
        int x,y;
        cin>>y>>x;
        map[x-1][y-1]=1;
        //fill the surrounding cells of the treasure with appropriate numbers
        isi(map,x-1,y-1+1,2);//east
        isi(map,x-1,y-1-1,2);//west
        isi(map,x-1-1,y-1,2);//north
        isi(map,x-1+1,y-1,2);//south
        //mark the surrounding cells of the treasure with appropriate numbers
        tanda(n,x,y,map);
    }
    //print the treasure map
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
