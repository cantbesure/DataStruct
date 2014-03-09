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
#include <cstring>
#include <map>
#define eps 1e-9
#define init 30;
#define increse 10;
using namespace std;
typedef long long LL;


class Node  //节点
{
public:
    Node();
    int data;
    Node *next;
    friend class Linklist;
};

class Linklist  //操作链表
{
public:
    Linklist();
    virtual ~Linklist();
    void Create(Linklist & l);
    int Length(Linklist & l);
    Node * head;
} ;

Linklist::Linklist()
{
    head=NULL;
}

Linklist::~Linklist()
{
    delete head;
}
Node::Node()
{
    this->data=0;
    this->next=NULL;
}

void Linklist::Create(Linklist & l)  //建表
{
    int n;
    cout<<"Plz Input The Number"<<endl;
    cin>>n;
    Node * p;
    for (int i=n;i>0;i--)
    {
        p=new Node;
        p->data=i;
        p->next=l.head;
        l.head=p;
    }
    while (p->next)
        p=p->next;
    p->next=l.head;
}

int Linklist::Length(Linklist & l)  //测深
{
    Node *p=l.head;
    int cnt=0;
    while (p->next!=l.head)
    {
        cnt++;
        p=p->next;
    }
    cnt++;
    return cnt;
}

int main()
{
    //freopen("in.txt","r",stdin);
    int m;
    Linklist l;
    l.Create(l);
    cout<<"Plz Input The Pos To Kick Out"<<endl;
    cin>>m;
    Node *p,*q,*r;
    p=l.head;
    int t=1;
    while (l.Length(l)>1)
    {
        for (int i=0;i<m-1;i++)
        {
            q=p;
            p=p->next;
        }
        if (p==l.head)
        {
            r=p;
            q->next=p->next;
            l.head=p->next;
            p=l.head;
        }
        else
        {
            r=p;
            q->next=p->next;
            p=p->next;
        }
        cout<<"No."<<t++<<" Out Is "<<r->data<<endl;
        //cout<<l.Length(l)<<endl;
    }
    cout<<"No."<<t++<<" Out Is "<<p->data<<endl;
    return 0;
}

