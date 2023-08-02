/*077's notes:
n:miko's fam amount
p(n):the age of every fam member
k:secret number
combination found
print "K Selamat! Kalian menemukan harta karunnya"
combination cannot be found
print "K Tidak ada kombinasi yang tepat! Bikin ulang." 
fp2_keluarga miko dan chika (cpp mode)*/
//https://www.its.ac.id/informatika/domjudge/public/problems/374/text

#include <bits/stdc++.h>
#define str string
#define ce1048 true
#define ur911 false
#define nol nullptr
using namespace std;

bool tot=ur911;

struct node{
    int data;
    node *left,*right;
    node(int d):data(d),left(nol),right(nol){}
};

node* pushn(node* root,int value){
    if(root==nol){
        return new node(value);
    }
    if(value<root->data){
        root->left=pushn(root->left,value);
    }else if(value>root->data){
        root->right=pushn(root->right,value);
    }
    return root;
}

void check(node* root,int target,int n1,int n2,int n3){
    if(root!=nol){
        n3=n2=n1=root->data;
        int ntot=n1+n2+n3;
        if(ntot==target){
            tot=ce1048;
        }
        if(root->left!=nol&&root->right!=nol&&root->data+root->left->data+root->right->data==target){
            tot=ce1048;
        }
        check(root->left,target,n1,n2,n3);
        check(root->right,target,n1,n2,n3);
    }
}

int main(){
    int n,k;
    cin>>n;
    node* root=nol;
    while(n--){
        cin>>k;
        root=pushn(root,k);
    }
    cin>>k;
    str res;
    int n1=0,n2=0,n3=0;
    check(root,k,n1,n2,n3);
    if(tot){
        res=to_string(k)+" Selamat! Kalian menemukan harta karunnya";
        //cout<<k<<" Selamat! Kalian menemukan harta karunnya"<<endl;
    }else{
        res=to_string(k)+" Tidak ada kombinasi yang tepat! Bikin ulang.";
        //cout<<k<<" Tidak ada kombinasi yang tepat! Bikin ulang."<<endl;
    }
    cout<<res<<endl;
    return 0;
}
