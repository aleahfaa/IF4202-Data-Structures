/*077's notes:
IN:insert/push
FD:level;print “on level x” if exists, else print “no {x}”
RK:get the x-th number in an ascending sequence
PH:path;print “{path to x}” if x exists, else print “no {x}”
L:left child
R:right child
S:arrived at the destination
STOP:stop the program, print “done”.
output based on the command desciption
fp_all bst (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

//node structure for bst (binary search tree)
struct bstnode{
    bstnode *left,*right;
    int key;
    int level;
    string path;
    //constructor to initialize node
    bstnode(int value,int lvl,string pth){
        key=value;
        level=lvl;
        path=pth;
        left=nullptr;
        right=nullptr;
    }
};

//bst structure
struct bst{
    bstnode* root;
    //initialize bst
    void init(){
        root=nullptr;
    }
    //check if bst is empty
    bool check(){//check it's empty or nah
        return root==nullptr;
    }
    //find a value in the bst
    bool find(int value){
        bstnode* temp=search(root,value);
        return temp&&temp->key==value;
    }
    //insert a value into the bst
    void push(int value){
        if(!find(value)){
            root=insert(root,value,1,"");
        }
    }
    //print the level of a value in the bst
    void plvl(int value){//print level
        bstnode* node=search(root,value);
        if(node){
            cout<<"on level "<<node->level<<endl;
        }else{
            cout<<"no "<<value<<endl;
        }
    }
    //print the value with a given rank in the bst
    void prank(int rank){//print rank
        int count=0;
        int result=inorder(root,rank,count);
        if(result==-1){
            cout<<"-1"<<endl;
        }
    }
    //print the path to a value in the bst
    void ppath(int value){//print path
        bstnode* node=search(root,value);
        if(node){
            string path=gpath(root,value);
            cout<<path<<endl;
        }else{
            cout<<"no "<<value<<endl;
        }
    }
private:
    //utility function to create new node
    bstnode* create(int value,int level,string path){
        return new bstnode(value,level,path);
    }
    //utility function to search for a value in bst
    bstnode* search(bstnode* root,int value){
        while(root!=nullptr){
            if(value<root->key){
                root=root->left;
            }else if(value>root->key){
                root=root->right;
            }else{
                return root;
            }
        }
        return nullptr;
    }
    //utility function to insert a value into the bst
    bstnode* insert(bstnode* root,int value,int level,string path){
        if(root==nullptr){
            return create(value,level,path);
        }
        if(value<root->key){
            root->left=insert(root->left,value,level+1,path+"L");
        }else if(value>root->key){
            root->right=insert(root->right,value,level+1,path+"R");
        }
        return root;
    }
    //utility function to print the value with a given rank in the bst (inorder tranversal)
    int inorder(bstnode* root,int rank,int& count){//inorder rank
        if(root==nullptr){
            return -1;
        }
        int leftres=inorder(root->left,rank,count);//left result
        if(leftres!=-1){
            return leftres;
        }
        count++;
        if(count==rank){
            cout<<root->key<<endl;
            return root->key;
        }
        return inorder(root->right,rank,count);
    }
    //utility function to get the path to a value in the bst
    string gpath(bstnode* root,int value){//get path
        string path;
        bstnode* current=root;
        while(current->key!=value){
            if(value<current->key){
                path+="L";
                current=current->left;
            }else if(value>current->key){
                path+="R";
                current=current->right;
            }
        }
        path+="S";
        return path;
    }
};

int main(){
    bst bts;
    bts.init();
    string cmd;
    int value;
    int rank;
    while(cin>>cmd){
        if(cmd=="IN"){
            cin>>value;
            if(!bts.find(value)){
                bts.push(value);
            }
        }else if(cmd=="FD"){
            cin >> value;
            bts.plvl(value);
        }else if(cmd=="RK"){
            cin>>rank;
            bts.prank(rank);
        }else if(cmd=="PH"){
            cin>>value;
            bts.ppath(value);
        }else if(cmd=="STOP"){
            cout<<"done"<<endl;
            break;
        }
    }
    return 0;
}
