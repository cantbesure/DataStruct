#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include <map>
#include <ctime>
#define eps 1e-9
#define init 30
#define increse 10
#define LmT 4
using namespace std;
typedef long long LL;

typedef struct Bnode
{
    int val;
    struct Bnode *left;
    struct Bnode *right;
} Bnode,*Btree;

void Build(Btree *rt,int val)
{
    if (*rt==NULL)
    {
        *rt=(Btree)malloc(sizeof(Bnode));
        (*rt)->val=val;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
        return ;
    }
    else if (val<=(*rt)->val)
        Build(&((*rt)->left),val);
    else
        Build(&((*rt)->right),val);
}

void InT(Btree rt)
{
    if (rt==NULL)
        return ;
    InT(rt->left);
    cout<<rt->val<<endl;
    InT(rt->right);
}

void Delete(Btree *rt,int val)
{
    if (*rt==NULL)
        return ;
    if ((*rt)->val==val)
    {
        if (!(*rt)->right)
        {
            Btree tmp=*rt;
            *rt=((*rt)->left);
            free(tmp);
        }
        else if (!(*rt)->left)
        {
            Btree tmp=*rt;
            *rt=((*rt)->right);
            free(tmp);
        }
        else
        {
            Btree tmp=*rt;
            Btree rr=(*rt)->left;
            while (rr->right)
                rr=rr->right;
            rr->right=(*rt)->right;
            *rt=((*rt)->left);
            free(tmp);
        }
        return ;
    }
    if (val<=(*rt)->val)
        Delete(&((*rt)->left),val);
    else
        Delete(&((*rt)->right),val);
}


int main()
{
    int n;
    cout<<"请输入节点数"<<endl;
    cin>>n;
    Btree tree=NULL;
    cout<<"请输入节点"<<endl;
    while (n--)
    {
        int a;
        cin>>a;
        Build(&tree,a);
    }
    cout<<"中序遍历排序二叉树"<<endl;
    InT(tree);
    while (true)
    {
        int b;
        cout<<"请输入要删除的节点"<<endl;
        cin>>b;
        Delete(&tree,b);
        cout<<"中序遍历删除后的排序二叉树"<<endl;
        InT(tree);
    }
    return 0;
}
