#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstring>
#define eps 1e-9
#define init 30;
#define increse 10;
using namespace std;
typedef long long LL;


class Node  //�ڵ�
{
public:
    Node();
    int data;
    int pwd;
    Node *next;
    friend class Linklist;
};

class Linklist  //��������
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

void Linklist::Create(Linklist & l)  //����
{
    int n;
    cout<<"����������"<<endl;
    cin>>n;
    Node * p;
    for (int i=n;i>0;i--)
    {
        p=new Node;
        p->data=i;
        p->next=l.head;
        cout<<"�������"<<i<<"���˵�mֵ"<<endl;
        cin>>p->pwd;
        l.head=p;
    }
    while (p->next)
        p=p->next;
    p->next=l.head;
}

int Linklist::Length(Linklist & l)  //����
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
    cout<<"�������ʼ��mֵ"<<endl;
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
            m=r->pwd;
        }
        else
        {
            r=p;
            q->next=p->next;
            p=p->next;
            m=r->pwd;

        }
        cout<<"No."<<t++<<"����"<<r->data<<endl;
        cout<<"��ǰmֵΪ"<<m<<endl;
        //cout<<l.Length(l)<<endl;
    }
    cout<<"No."<<t++<<"����"<<p->data<<endl;
    return 0;
}

