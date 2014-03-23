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
    char id[10];
    time_t in_time;//����ʱ��
    int cost;//�Ʒ�
} car;
//int lmt=0;
queue<car> wait;
vector<car> park;
vector<car> fee;

void  carin()
{
    if (park.size()<LMT)
    {
        car in;
        cin>>in.id;
        in.in_time=time(NULL);
        in.cost=0;
        park.push_back(in);
        cout<<in.id<<"������"<<endl;
    }
    else
    {
        car in;
        cin>>in.id;
        wait.push(in);
        cout<<in.id<<"���Ŷ�"<<endl;
    }
}

void carout()
{
    char id[10];
    cin>>id;
    for (vector<car>::iterator it=park.begin(); it!=park.end(); ++it )
    {
        if (!strcmp(it->id,id))
        {
            car out;
            strcpy(out.id,id);
            out.cost=time(NULL)-it->in_time;
            fee.push_back(out);
            park.erase(it);
            cout<<out.id<<"��ʻ��"<<endl;
            break;
        }

    }
    if (park.size()<LMT&&!wait.empty())
    {
        wait.front().in_time=time(NULL);
        park.push_back(wait.front());
        cout<<wait.front().id<<"�����Ŷӽ��볡��"<<endl;
        wait.pop();
    }
}

void printpark()
{
    if (park.empty())
    {
        cout<<"�����޳�"<<endl;
    }
    else
    {
        for (vector<car>::iterator it=park.begin();it!=park.end();++it)
        {
            cout<<"���ƺţ�"<<it->id<<"����ʱ��"<<it->in_time<<endl;
        }
    }
}

void printfee()
{
    if (fee.empty())
    {
        cout<<"û���շѼ�¼"<<endl;
    }
    else
    {
        for (vector<car>::iterator it=fee.begin();it!=fee.end();++it)
        {
            cout<<"���ƺţ�"<<it->id<<"�շ�"<<it->cost<<endl;
        }
    }
}

int main()
{
    while (true)
    {
        cout<<"****************"<<endl;
        cout<<"*1.�г��������*"<<endl;
        cout<<"*2.�г�����ʻ��*"<<endl;
        cout<<"*3.��ӡ�շ�״��*"<<endl;
        cout<<"*4.��ӡ������Ϣ*"<<endl;
        cout<<"*5.�˳�        *"<<endl;
        cout<<"****************"<<endl;
        int opt;
        cin>>opt;
        if (opt==1)
            carin();
        if (opt==2)
            carout();
        if (opt==3)
            printfee();
        if (opt==4)
            printpark();
        if (opt==5)
            break;

    }
    return 0;
}
