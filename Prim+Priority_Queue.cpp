#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<vector>
#include<cstdlib>
#include<string>
#include<cstring>
#include<map>
#include<ctime>
#define eps 1e-9
#define init 30
#define increse 10
#define LmT 4
using namespace std;
typedef long long LL;

const int maxx= 100;
class edge
{
public:
    int sta;
    int sto;
    int val;
    friend bool operator < (const edge &,const edge &);
};

bool operator <(const edge& e1,const edge &e2) //升序优先队列
{
    return e1.val>e2.val;
}

bool vis[maxx];//搜索记录
int weight[maxx][maxx];//各边权
int link[maxx][maxx];//邻接表，首位存个数

int main()
{
    int n,m;
    int tot,cur;
    int w,p,q;
    int rst;
    memset(vis,0,sizeof vis);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        link[i][0]=1;
    for (int i=0; i<m; i++)
    {
        cin>>p>>q>>w;
        weight[p][q]=weight[q][p]=w;
        link[p][link[p][0]++]=q;
        link[q][link[q][0]++]=p;
    }

    vis[0]=true;
    tot=1;
    cur=0;
    rst=0;
    edge tmp;
    priority_queue <edge> edges;
    while (tot++<n)
    {
        for (int i=1; i<link[cur][0]; i++)
        {
            if (!vis[link[cur][i]])
            {
                tmp.sta=cur;
                tmp.sto=link[cur][i];
                tmp.val=weight[tmp.sta][tmp.sto];
                edges.push(tmp);
            }
        }
        while (!edges.empty()&& vis[edges.top().sto])
            edges.pop();
        tmp=edges.top();
        vis[tmp.sto]=true;
        rst+=tmp.val;
        cur=tmp.sto;
        edges.pop();
    }
    cout<<rst<<endl;
    return 0;

}
