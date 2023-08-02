/*077's notes:
"15" to put the x in the bst (push)
"04" to remove the x from the bst (pop)
"89" to print all of the parents that has one child only with ascending order
print all of the parents that has one child only with ascending order
if there's no,print "use whatever means u must to control our population.just do it."
fp_moga tak hilang (cpp mode)*/

#include <bits/stdc++.h>
using namespace std;

//node structure
struct bstnode {
    bstnode *left,*right;
    int key;
    bstnode(int value):key(value),left(nullptr),right(nullptr){}
};

//bst class representing the bst(binary search tree)
class bst{
public:
    bstnode* root;
    bst():root(nullptr){}
    //function to insert a value into the bst
    void push(int value){
        root=pushrec(root,value);//insert recursive
    }
    //recursive function to insert a value into the bst
    bstnode* pushrec(bstnode* node,int value){
        if(node==nullptr){
            return new bstnode(value);
        }
        if(value<node->key){
            node->left=pushrec(node->left,value);
        }else if(value>node->key){
            node->right=pushrec(node->right,value);
        }
        return node;
    }
    //function to remove a value from the binary search tree
    void pop(int value){
        root=poprec(root,value);//remove recursive
    }
    //recursive function to remove a value from the binary search tree
    bstnode* poprec(bstnode* node,int value){
        if(node==nullptr){
            return nullptr;
        }
        if(value<node->key){
            node->left=poprec(node->left,value);
        }else if(value>node->key){
            node->right=poprec(node->right,value);
        }else{
            //if the node has no children or only one child
            if(node->left==nullptr){
                bstnode* temp=node->right;
                delete node;
                return temp;
            }else if(node->right==nullptr){
                bstnode* temp=node->left;
                delete node;
                return temp;
            }
            //if the node has two children
            bstnode* temp=findmin(node->right);
            node->key=temp->key;
            node->right=poprec(node->right,temp->key);
        }
        return node;
    }
    //function to find the minimum node in a subtree
    bstnode* findmin(bstnode* node){
        while(node->left!=nullptr){
            node=node->left;
        }
        return node;
    }
    //function to find and store the leaves of the binary search tree
    void findleaves(priority_queue<int,vector<int>,greater<int>>&leaves){
        findleavesrec(root,leaves);//find leaves recursive
    }
    //recursive function to find and store the leaves of the binary search tree
    void findleavesrec(bstnode* node,priority_queue<int,vector<int>,greater<int>>&leaves){
        if(node!=nullptr){
            //traverse the left subtree
            findleavesrec(node->left,leaves);
            //if the node is a leaf (either left child or right child is null)
            if((!node->left&&node->right)||(node->left&&!node->right)){
                leaves.push(node->key);//store the leaf value in the priority queue
            }
            //traverse the right subtree
            findleavesrec(node->right,leaves);
        }
    }
};

int main(){
    int n;
    cin>>n;
    bst bts;
    priority_queue<int,vector<int>,greater<int>>leaves;
    for(int i=0;i<n;i++){
        int opr;//operation
        cin>>opr;
        if(opr==15) {
            int value;
            cin>>value;
            bts.push(value);//insert the value into the bst
        }else if(opr==4){
            int value;
            cin>>value;
            bts.pop(value);//remove the value from the bst
        }else if(opr==89){
            bts.findleaves(leaves);//find and store the leaves of the bst
            int flag=leaves.size();
            int arr[flag];
            if(leaves.empty()){
                cout<<"Use whatever means you must to control our population. Just do it."<<endl;
            }else{
                //store the leaves in an array in ascending order
                for(int i=0;i<flag;i++){
                    arr[i]=leaves.top();
                    leaves.pop();
                }
                //print the leaves in ascending order
                for (int i=0;i<flag;i++) {
                    cout<<arr[i]<<" ";
                }
                cout<<endl;
            }
        }
    }
    return 0;
}
