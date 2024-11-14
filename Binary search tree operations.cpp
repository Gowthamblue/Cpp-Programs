#include <bits/stdc++.h>
using namespace std;
//Binary Search Tree

class Node
{
    public:
        int key;
        struct Node*left,*right;
};
Node*newnode(int data)
{
    Node*n=new Node();
    n->key=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
Node*Insert(Node*root,int data)
{
    Node*m=newnode(data);
    if(root==NULL) 
    {
        root=m;
    }
    else
    {
        queue<Node*>q;
        q.push(root);
        Node*front=NULL;
        while(!q.empty())
        {
            front=q.front();
            q.pop();
            if(front->key > m->key)
            {
                if(front->left==NULL)
                {
                    front->left=m;
                    break;
                }
                else
                {
                    q.push(front->left);
                }
            }
            if(front->key < m->key)
            {
                if(front->right==NULL)
                {
                    front->right=m;
                }
                else
                {
                    q.push(front->right);
                }
            }
        }
    }
            return root;
}
Node*delete_(int data,Node*root)
{
    
}
Node*minimum(Node*root)
{
    if(root->left==NULL)
    {
        return root;
    }
    else
    {
        return minimum(root->left);
    }
}
Node*maximum(Node*root)
{
    if(root->right==NULL)
    {
        return root;
    }
    else
    {
        return maximum(root->right);
    }
}
Node*delete_Node(Node*root,int data)
{
    if(root==NULL)
    {
        cout<<"No elements"<<endl;
    }
    else if(data < root->key)
    {
        root->left=delete_Node(root->left,data);
    }
    else if(data > root->key)
    {
        root->right=delete_Node(root->right,data);
    }
    else
    {
        if(root->left!=NULL && root->right!=NULL)
        {
            Node*temp=root;
            Node*min_right=minimum(temp->right);
            root->key=min_right->key;
            root->right=delete_Node(root->right,min_right->key);
        }
        else if(root->left!=NULL)
        {
            root=root->left;
        }
        else if(root->right!=NULL)
        {
            root=root->right;
        }
        else
        {
            root=NULL;
        }
    }
    return root;
}
            
Node* display(Node* root)
{
    if(root==NULL)
    {
        cout<<"Empty Tree";
    }
    else
    {
        queue<Node*>q;
        q.push(root);
        Node*front=NULL;
        while(!q.empty())
        {
            front=q.front();
            q.pop();
            cout<<front->key<<" ";
            if(front->left!=NULL)
            {
                q.push(front->left);
            }
            if(front->right!=NULL)
            {
                q.push(front->right);
            }
            
        }
        cout<<endl;
        
    }
    return root;
}



int main() {
    Node*root=NULL;
    root=Insert(root,15);
    root=Insert(root,10);
    root=Insert(root,5);
    root=Insert(root,18);
    root=Insert(root,30);
    root=Insert(root,61);
    root=Insert(root,59);
    root=Insert(root,52);
    root=Insert(root,48);
    root=display(root);
 //   root=minimum(root);
//    root=display(root);
    root=delete_Node(root,48);
    root=display(root);
    
}
                
