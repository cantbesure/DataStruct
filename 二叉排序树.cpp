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

void Build(Btree *rt,int val)   //构造一棵二叉排序树
{
    if (*rt==NULL)
    {
        *rt=(Btree)malloc(sizeof(Bnode));
        (*rt)->val=val;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
        return ;
    }
    else if (val<=(*rt)->val)   //递归构造左子树
        Build(&((*rt)->left),val);
    else    //递归构造右子树
        Build(&((*rt)->right),val);
}

void InT(Btree rt)  //中序遍历二叉排序数
{
    if (rt==NULL)
        return ;
    InT(rt->left);  //遍历左子树
    cout<<rt->val<<endl;
    InT(rt->right); //遍历右子树
}

void Delete(Btree *rt,int val)  //删除结点
{
    if (*rt==NULL)
        return ;
    if ((*rt)->val==val)    //找到该结点，进行删除操作
    {
        if (!(*rt)->right)  //如果右子树为空，直接将左子树代替原结点
        {
            Btree tmp=*rt;
            *rt=((*rt)->left);
            free(tmp);
        }
        else if (!(*rt)->left)  //如果左子树为空，直接将将右子树代替原结点
        {
            Btree tmp=*rt;
            *rt=((*rt)->right);
            free(tmp);
        }
        else        //若左右子树都不为空
        {
            Btree tmp=*rt;
            Btree rr=(*rt)->right;
            while (rr->left)   //找待删结点左子树的最右结点
                rr=rr->left;
            rr->left=(*rt)->left; //将待删结点的右子树接到其后
            *rt=((*rt)->right);  //用待删结点的左子树代替原结点
            free(tmp);
        }
        return ;
    }
    if (val<=(*rt)->val)    //如果当前值小，遍历左子树
        Delete(&((*rt)->left),val);
    else                    //如果当前值大，遍历右子树
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

/*test data
9
7 8 3 2 6 1 5 9 4
*/
