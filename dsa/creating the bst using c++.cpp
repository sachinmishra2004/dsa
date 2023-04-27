// C++ Code to insert node and to print inorder traversal
// using iteration

#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
    
};


 Node* insertintobst(Node*root, int d){
    //base case
    if(root==NULL){
        root= new Node(d);
        return root;
    }
    if(d> root->data){
        // right part me insert karna hai
        root->right = insertintobst(root->right,d);
    }
    else{
        //left part main insert karrio
        root->left   = insertintobst(root->left, d);
    }
    return root;
 }

 void takeinput(Node*&root){
    int data;
    cin>>data;
    while(data!=-1){
         root = insertintobst(root, data);
        cin>>data;
    }
 }
void inorder(Node*root){
    // base caes
    if(root== NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(Node*root){
    //base case
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}


int main()
{
    Node* root = NULL;

    cout<<"enter the data create bst"<<endl;
    takeinput(root);
    cout<<endl<<"printing the inorder"<<endl;
   inorder(root);
   cout<<endl <<"printing the postorder"<<endl;
    postorder(root);

    return 0;
}