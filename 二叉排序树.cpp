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

void Build(Btree *rt,int val)   //����һ�ö���������
{
    if (*rt==NULL)
    {
        *rt=(Btree)malloc(sizeof(Bnode));
        (*rt)->val=val;
        (*rt)->left=NULL;
        (*rt)->right=NULL;
        return ;
    }
    else if (val<=(*rt)->val)   //�ݹ鹹��������
        Build(&((*rt)->left),val);
    else    //�ݹ鹹��������
        Build(&((*rt)->right),val);
}

void InT(Btree rt)  //�����������������
{
    if (rt==NULL)
        return ;
    InT(rt->left);  //����������
    cout<<rt->val<<endl;
    InT(rt->right); //����������
}

void Delete(Btree *rt,int val)  //ɾ�����
{
    if (*rt==NULL)
        return ;
    if ((*rt)->val==val)    //�ҵ��ý�㣬����ɾ������
    {
        if (!(*rt)->right)  //���������Ϊ�գ�ֱ�ӽ�����������ԭ���
        {
            Btree tmp=*rt;
            *rt=((*rt)->left);
            free(tmp);
        }
        else if (!(*rt)->left)  //���������Ϊ�գ�ֱ�ӽ�������������ԭ���
        {
            Btree tmp=*rt;
            *rt=((*rt)->right);
            free(tmp);
        }
        else        //��������������Ϊ��
        {
            Btree tmp=*rt;
            Btree rr=(*rt)->right;
            while (rr->left)   //�Ҵ�ɾ��������������ҽ��
                rr=rr->left;
            rr->left=(*rt)->left; //����ɾ�����������ӵ����
            *rt=((*rt)->right);  //�ô�ɾ��������������ԭ���
            free(tmp);
        }
        return ;
    }
    if (val<=(*rt)->val)    //�����ǰֵС������������
        Delete(&((*rt)->left),val);
    else                    //�����ǰֵ�󣬱���������
        Delete(&((*rt)->right),val);
}


int main()
{
    int n;
    cout<<"������ڵ���"<<endl;
    cin>>n;
    Btree tree=NULL;
    cout<<"������ڵ�"<<endl;
    while (n--)
    {
        int a;
        cin>>a;
        Build(&tree,a);
    }
    cout<<"����������������"<<endl;
    InT(tree);
    while (true)
    {
        int b;
        cout<<"������Ҫɾ���Ľڵ�"<<endl;
        cin>>b;
        Delete(&tree,b);
        cout<<"�������ɾ��������������"<<endl;
        InT(tree);
    }
    return 0;
}

/*test data
9
7 8 3 2 6 1 5 9 4
*/
