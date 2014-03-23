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
#define LMT 4
#define maxx 100
using namespace std;
typedef long long LL;

int row[8];
int vis[3][8];
int rst=0;

void dfs(int cur)
{
    int i,j;
    if (cur==8)
    {
        rst++;
        //cout<<rst<<endl;
        for (int i=0;i<8;i++)
            cout<<row[i]<<" ";
        cout<<endl;
    }
    else for (int i=0;i<8;i++)
    {
        if (!vis[0][i]&&!vis[1][cur+i]&&!vis[2][cur-i+8])
        {
            row[cur]=i;
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+8]=1;
            dfs(cur+1);
            vis[0][i]=vis[1][cur+i]=vis[2][cur-i+8]=0;
        }
    }
}
int main()
{
    memset(vis,0,sizeof vis);
    dfs(0);
    //cout<<rst<<endl;
    return 0;
}
