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
    for (scanf("%c%c",&first,&second); second!='#'; rst=scanf("%c%c",&first,&second))
    {
        p=getNode(second);
        q.push(p);
        if (first=='#')
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
    if (rt==NULL)
        return 0;
    int d1,d2;
    d1=depth(rt->first);
    d2=depth(rt->nextsibling);
    return max(d1,d2)+1;

}

int main()
{
    Tree tree;
    creatTree(tree);
    cout<<depth(tree)<<endl;
    return 0;
}

