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
    time_t in_time;//储存时间
    int cost;//计费
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
        cout<<in.id<<"车进入"<<endl;
    }
    else
    {
        car in;
        cin>>in.id;
        wait.push(in);
        cout<<in.id<<"车排队"<<endl;
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
            cout<<out.id<<"车驶出"<<endl;
            break;
        }

    }
    if (park.size()<LMT&&!wait.empty())
    {
        wait.front().in_time=time(NULL);
        park.push_back(wait.front());
        cout<<wait.front().id<<"车从排队进入场内"<<endl;
        wait.pop();
    }
}

void printpark()
{
    if (park.empty())
    {
        cout<<"场内无车"<<endl;
    }
    else
    {
        for (vector<car>::iterator it=park.begin();it!=park.end();++it)
        {
            cout<<"车牌号："<<it->id<<"进入时间"<<it->in_time<<endl;
        }
    }
}

void printfee()
{
    if (fee.empty())
    {
        cout<<"没有收费记录"<<endl;
    }
    else
    {
        for (vector<car>::iterator it=fee.begin();it!=fee.end();++it)
        {
            cout<<"车牌号："<<it->id<<"收费"<<it->cost<<endl;
        }
    }
}

int main()
{
    while (true)
    {
        cout<<"****************"<<endl;
        cout<<"*1.有车请求进入*"<<endl;
        cout<<"*2.有车请求驶出*"<<endl;
        cout<<"*3.打印收费状况*"<<endl;
        cout<<"*4.打印场内信息*"<<endl;
        cout<<"*5.退出        *"<<endl;
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
