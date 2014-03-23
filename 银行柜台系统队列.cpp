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
#include <ctime>
#define eps 1e-9
#define init 30
#define increse 10
#define LMT 100
using namespace std;
typedef long long LL;

typedef struct
{
    char type;//�˿�����
    int id;//�˿ͺ���
} client;

queue<client> ta;//��ͬqueue
queue<client> tb;
queue<client> tc;

int cnt=0;//ȡ�ż���
bool a,b1,b2,b3,c1,c2;//����̨״̬
int na,nb1,nb2,nb3,nc1,nc2;//����̨����

void client_in()
{
    client in;
    in.id=++cnt;
    cin>>in.type;
    switch (in.type)
    {
    case 'a':
        ta.push(in);
        cout<<"a��˿�"<<in.id<<"���Ժ�"<<endl;
        if (a)
        {
            cout<<"��"<<ta.front().id<<"��a��̨����ҵ��"<<endl;
            na=ta.front().id;
            a=false;
            ta.pop();
        }
        break;
    case 'b':
        tb.push(in);
        cout<<"b��˿�"<<in.id<<"���Ժ�"<<endl;
        if (b1)
        {
            cout<<"��"<<tb.front().id<<"��b1��̨����ҵ��"<<endl;
            nb1=tb.front().id;
            b1=false;
            tb.pop();
        }
        else if (b2)
        {
            cout<<"��"<<tb.front().id<<"��b2��̨����ҵ��"<<endl;
            nb2=tb.front().id;
            b2=false;
            tb.pop();
        }
        else if (b3)
        {
            cout<<"��"<<tb.front().id<<"��b3��̨����ҵ��"<<endl;
            nb3=tb.front().id;
            b3=false;
            tb.pop();
        }
        break;
    case 'c':
        tc.push(in);
        cout<<"c��˿�"<<in.id<<"���Ժ�"<<endl;
        if (c1)
        {
            cout<<"��"<<tc.front().id<<"��c1��̨����ҵ��"<<endl;
            nc1=tc.front().id;
            c1=false;
            tc.pop();
        }
        else if (c2)
        {
            cout<<"��"<<tc.front().id<<"��c2��̨����ҵ��"<<endl;
            nc2=tc.front().id;
            c2=false;
            tc.pop();
        }
        else    if (b1)
        {
            cout<<"��"<<tc.front().id<<"��b1��̨����ҵ��"<<endl;
            nb1=tc.front().id;
            b1=false;
            tc.pop();
        }
        else if (b2)
        {
            cout<<"��"<<tc.front().id<<"��b2��̨����ҵ��"<<endl;
            nb2=tc.front().id;
            b2=false;
            tc.pop();
        }
        else if (b3)
        {
            cout<<"��"<<tc.front().id<<"��b3��̨����ҵ��"<<endl;
            nb3=tc.front().id;
            b3=false;
            tc.pop();
        }
        break;
    }
}
void client_out()
{
    int tt;
    cout<<"�������������Ĵ�����"<<endl;
    cin>>tt;
    while (tt--)
    {
        char cnter[2];
        cout<<"�������������Ĵ���"<<endl;
        cin>>cnter;
        if (!strcmp(cnter,"a"))
        {
            a=true;
            if (!ta.empty())
            {
                cout<<"��"<<ta.front().id<<"��a��̨����ҵ��"<<endl;
                na=ta.front().id;
                a=false;
                ta.pop();
            }
        }
        else if (!strcmp(cnter,"b1"))
        {
            b1=true;
            if (!tb.empty())
            {
                cout<<"��"<<tb.front().id<<"��b1��̨����ҵ��"<<endl;
                nb1=tb.front().id;
                b1=false;
                tb.pop();
            }
            else if (!tc.empty())//���b��ҵ���Ѿ�������c����ȥb
            {
                cout<<"��"<<tc.front().id<<"��b1��̨����ҵ��"<<endl;
                nb1=tc.front().id;
                b1=false;
                tc.pop();
            }
        }
        else if (!strcmp(cnter,"b2"))
        {
            b2=true;
            if (!tb.empty())
            {
                cout<<"��"<<tb.front().id<<"��b2��̨����ҵ��"<<endl;
                nb2=tb.front().id;
                b2=false;
                tb.pop();
            }
            else if (!tc.empty())
            {
                cout<<"��"<<tc.front().id<<"��b2��̨����ҵ��"<<endl;
                nb2=tc.front().id;
                b2=false;
                tc.pop();
            }
        }
        else if (!strcmp(cnter,"b3"))
        {
            b3=true;
            if (!tb.empty())
            {
                cout<<"��"<<tb.front().id<<"��b3��̨����ҵ��"<<endl;
                nb3=tb.front().id;
                b3=false;
                tb.pop();
            }
            else if (!tc.empty())
            {
                cout<<"��"<<tc.front().id<<"��b3��̨����ҵ��"<<endl;
                nb3=tc.front().id;
                b3=false;
                tc.pop();
            }
        }
        else if (!strcmp(cnter,"c1"))
        {
            c1=true;
            if (!tc.empty())
            {
                cout<<"��"<<tc.front().id<<"��c1��̨����ҵ��"<<endl;
                nc1=tc.front().id;
                c1=false;
                tc.pop();
            }
        }
        else if (!strcmp(cnter,"c2"))
        {
            c2=true;
            if (!tc.empty())
            {
                cout<<"��"<<tc.front().id<<"��c2��̨����ҵ��"<<endl;
                nc2=tc.front().id;
                c2=false;
                tc.pop();
            }
        }
    }
}


void print_client()
{
    if (!a)
        cout<<na<<"�Ź˿���a���ڷ���"<<endl;
    else
        cout<<"a���ڿ���"<<endl;
    if (!b1)
        cout<<nb1<<"�Ź˿���b1���ڷ���"<<endl;
    else
        cout<<"b1���ڿ���"<<endl;
    if (!b2)
        cout<<nb2<<"�Ź˿���b2���ڷ���"<<endl;
    else
        cout<<"b2���ڿ���"<<endl;
    if (!b3)
        cout<<nb3<<"�Ź˿���b3���ڷ���"<<endl;
    else
        cout<<"b3���ڿ���"<<endl;
    if (!c1)
        cout<<nc1<<"�Ź˿���c1���ڷ���"<<endl;
    else
        cout<<"c1���ڿ���"<<endl;
    if (!c2)
        cout<<nc2<<"�Ź˿���c2���ڷ���"<<endl;
    else
        cout<<"c2���ڿ���"<<endl;

}

int main()
{
    a=b1=b2=b3=c1=c2=true;
    while (true)
    {
        cout<<"****************"<<endl;
        cout<<"*1.�˿��ú�    *"<<endl;
        cout<<"*2.�������    *"<<endl;
        cout<<"*3.��ӡ������Ϣ*"<<endl;
        cout<<"*4.�˳�        *"<<endl;
        cout<<"****************"<<endl;
        int opt;
        cin>>opt;
        if (opt==1)
            client_in();
        if (opt==2)
            client_out();
        if (opt==3)
            print_client();
        else
            break;

    }
    return 0;
}
