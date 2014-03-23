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
    char type;//顾客类型
    int id;//顾客号码
} client;

queue<client> ta;//不同queue
queue<client> tb;
queue<client> tc;

int cnt=0;//取号计数
bool a,b1,b2,b3,c1,c2;//各柜台状态
int na,nb1,nb2,nb3,nc1,nc2;//各柜台号码

void client_in()
{
    client in;
    in.id=++cnt;
    cin>>in.type;
    switch (in.type)
    {
    case 'a':
        ta.push(in);
        cout<<"a类顾客"<<in.id<<"请稍候"<<endl;
        if (a)
        {
            cout<<"请"<<ta.front().id<<"到a柜台办理业务"<<endl;
            na=ta.front().id;
            a=false;
            ta.pop();
        }
        break;
    case 'b':
        tb.push(in);
        cout<<"b类顾客"<<in.id<<"请稍候"<<endl;
        if (b1)
        {
            cout<<"请"<<tb.front().id<<"到b1柜台办理业务"<<endl;
            nb1=tb.front().id;
            b1=false;
            tb.pop();
        }
        else if (b2)
        {
            cout<<"请"<<tb.front().id<<"到b2柜台办理业务"<<endl;
            nb2=tb.front().id;
            b2=false;
            tb.pop();
        }
        else if (b3)
        {
            cout<<"请"<<tb.front().id<<"到b3柜台办理业务"<<endl;
            nb3=tb.front().id;
            b3=false;
            tb.pop();
        }
        break;
    case 'c':
        tc.push(in);
        cout<<"c类顾客"<<in.id<<"请稍候"<<endl;
        if (c1)
        {
            cout<<"请"<<tc.front().id<<"到c1柜台办理业务"<<endl;
            nc1=tc.front().id;
            c1=false;
            tc.pop();
        }
        else if (c2)
        {
            cout<<"请"<<tc.front().id<<"到c2柜台办理业务"<<endl;
            nc2=tc.front().id;
            c2=false;
            tc.pop();
        }
        else    if (b1)
        {
            cout<<"请"<<tc.front().id<<"到b1柜台办理业务"<<endl;
            nb1=tc.front().id;
            b1=false;
            tc.pop();
        }
        else if (b2)
        {
            cout<<"请"<<tc.front().id<<"到b2柜台办理业务"<<endl;
            nb2=tc.front().id;
            b2=false;
            tc.pop();
        }
        else if (b3)
        {
            cout<<"请"<<tc.front().id<<"到b3柜台办理业务"<<endl;
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
    cout<<"请输入结束服务的窗口数"<<endl;
    cin>>tt;
    while (tt--)
    {
        char cnter[2];
        cout<<"请输入结束服务的窗口"<<endl;
        cin>>cnter;
        if (!strcmp(cnter,"a"))
        {
            a=true;
            if (!ta.empty())
            {
                cout<<"请"<<ta.front().id<<"到a柜台办理业务"<<endl;
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
                cout<<"请"<<tb.front().id<<"到b1柜台办理业务"<<endl;
                nb1=tb.front().id;
                b1=false;
                tb.pop();
            }
            else if (!tc.empty())//如果b的业务已经办理完c可以去b
            {
                cout<<"请"<<tc.front().id<<"到b1柜台办理业务"<<endl;
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
                cout<<"请"<<tb.front().id<<"到b2柜台办理业务"<<endl;
                nb2=tb.front().id;
                b2=false;
                tb.pop();
            }
            else if (!tc.empty())
            {
                cout<<"请"<<tc.front().id<<"到b2柜台办理业务"<<endl;
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
                cout<<"请"<<tb.front().id<<"到b3柜台办理业务"<<endl;
                nb3=tb.front().id;
                b3=false;
                tb.pop();
            }
            else if (!tc.empty())
            {
                cout<<"请"<<tc.front().id<<"到b3柜台办理业务"<<endl;
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
                cout<<"请"<<tc.front().id<<"到c1柜台办理业务"<<endl;
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
                cout<<"请"<<tc.front().id<<"到c2柜台办理业务"<<endl;
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
        cout<<na<<"号顾客在a窗口服务"<<endl;
    else
        cout<<"a窗口空闲"<<endl;
    if (!b1)
        cout<<nb1<<"号顾客在b1窗口服务"<<endl;
    else
        cout<<"b1窗口空闲"<<endl;
    if (!b2)
        cout<<nb2<<"号顾客在b2窗口服务"<<endl;
    else
        cout<<"b2窗口空闲"<<endl;
    if (!b3)
        cout<<nb3<<"号顾客在b3窗口服务"<<endl;
    else
        cout<<"b3窗口空闲"<<endl;
    if (!c1)
        cout<<nc1<<"号顾客在c1窗口服务"<<endl;
    else
        cout<<"c1窗口空闲"<<endl;
    if (!c2)
        cout<<nc2<<"号顾客在c2窗口服务"<<endl;
    else
        cout<<"c2窗口空闲"<<endl;

}

int main()
{
    a=b1=b2=b3=c1=c2=true;
    while (true)
    {
        cout<<"****************"<<endl;
        cout<<"*1.顾客拿号    *"<<endl;
        cout<<"*2.服务结束    *"<<endl;
        cout<<"*3.打印窗口信息*"<<endl;
        cout<<"*4.退出        *"<<endl;
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
