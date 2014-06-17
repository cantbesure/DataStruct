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

typedef struct Node
{
    char ele;
    struct Node *first,*nextsibling;

} Node,*Tree;

Tree getNode(char e)
{
    Tree p;
    p=(Tree)malloc(sizeof(Node));
    if (!p) exit(0);
    p->ele=e;
    p->first=NULL;
    p->nextsibling=NULL;
    return p;
}

void creatTree(Tree &rt)
{
    char first=' ',second=' ';
    int rst=0;
    queue<Tree> q;
    Tree p,s,r;
    rt=NULL;
    for (scanf("%c%c",&first,&second); second!='*';rst=scanf("%c%c",&first,&second))
    {
        p=getNode(second);
        q.push(p);
        if (first=='*')
            rt=p;
        else
        {
            s=q.front();
            while (s->ele!=first)
            {
                q.pop();
                s=q.front();
            }
            if (s->first==NULL)
            {
                s->first=p;
                r=p;
            }
            else
            {
                r->nextsibling=p;
                r=p;
            }
        }
    }
}

int depth(Tree rt)
{
    int d1,d2;
    if (rt==NULL)
        return 0;
    d1=depth(rt->first);
    d2=depth(rt->nextsibling);
    return max(d1+1,d2);

}

int main()
{
    Tree tree;
    cout<<"请输入一个树，以“*”开头，以“**”结束,按层次顺序从左至右输入边"<<endl;
    creatTree(tree);
    cout<<"树的深度为";
    cout<<depth(tree)-1<<endl;
    return 0;
}

/*
TEST CASE

*AABACADAECFDGFHHIIJ**

*/
