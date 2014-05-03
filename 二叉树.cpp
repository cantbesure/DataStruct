#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <cstdlib>
#include <string>
#include <map>
using namespace std;
typedef long long LL;

typedef struct Bnode
{
    char ele;
    struct Bnode *left;
    struct Bnode *right;
}Bnode,*Btree;


void createBtree(Btree * rt)
{
    char ch;
    cin>>ch;
    if (ch=='.')
        (*rt)=NULL;
    else{
        if(!(*rt=(Btree)malloc(sizeof(Bnode)))){
            exit(-1);
        }
        (*rt)->ele=ch;
        createBtree(&((*rt)->left));
        createBtree(&((*rt)->right));
    }
}

void PreT(Btree rt)
{
    if (rt!=NULL)
    {
        cout<<rt->ele;
        PreT(rt->left);
        PreT(rt->right);
    }
}

void InT(Btree rt)
{
    if (rt!=NULL)
    {
        InT(rt->left);
        cout<<rt->ele;
        InT(rt->right);
    }
}

void PostT(Btree rt)
{
     if (rt!=NULL)
    {
        PostT(rt->left);
        PostT(rt->right);
        cout<<rt->ele;
    }
}

void NoPreT(Btree rt)
{
    if (rt==NULL) return ;
    stack <Btree> t;
    t.push(rt);
    while (!t.empty())
    {
        Btree tmp= t.top();
        cout<<tmp->ele;
        t.pop();
        if (tmp->right!=NULL)
            t.push(tmp->right);
        if (tmp->left!=NULL)
            t.push(tmp->left);

    }
}

bool visit(Btree rt)
{
    if (rt!=NULL)
    {
        cout<<rt->ele;
        return true;
    }
    else
        return false;
}

void NoLevT(Btree rt)
{
    queue <Btree> q;
    Btree tmp;
    tmp=rt;
    if (visit(tmp))
        q.push(tmp);
    while (!q.empty())
    {
        tmp=q.front();
        q.pop();
        if (visit(tmp->left))
            q.push(tmp->left);
        if (visit(tmp->right))
            q.push(tmp->right);
    }
}

int depth(Btree rt)
{
    if (rt==NULL)
        return 0;
    int d1,d2;
    d1=depth(rt->left);
    d2=depth(rt->right);
    return max(d1,d2)+1;
}

int main()
{
    Btree tree=NULL;
    createBtree(&tree);
    PreT(tree);
    cout<<endl;
    InT(tree);
    cout<<endl;
    PostT(tree);
    cout<<endl;
    NoPreT(tree);
    cout<<endl;
    NoLevT(tree);
    cout<<endl;
    cout<<depth(tree)<<endl;
    return 0;
}
