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
#define LmT 4
using namespace std;
typedef long long LL;

const int maxx= 100;

bool vis[maxx];
int weight[maxx][maxx];
int link[maxx][maxx];

void bfs(int index)
{
    queue <int> q;
    cout<<index<<endl;
    vis[index]=true;
    q.push(index);
    while (!q.empty())
    {
        int tmp=q.front();
        for (int i=1;i<link[tmp][0];i++)
        {
            if (!vis[link[tmp][i]])
            {
                cout<<link[tmp][i]<<endl;
                q.push(link[tmp][i]);
                vis[link[tmp][i]]=true;
            }
        }
        q.pop();
    }

}

int main()
{
    int n,m;
    cin>>n>>m;
    int p,q;
    memset(vis,0,sizeof vis);
    for (int i=0;i<n;i++)
        link[i][0]=1;
    for (int i=0;i<m;i++)
    {
        cin>>p>>q;
        link[p][link[p][0]++]=q;
        link[q][link[q][0]++]=p;
    }
    bfs(0);
    return 0;
}


/*test data
8 9
0 2
0 1
1 2
1 3
1 5
2 4
4 7
5 7
6 7
*/

/*output
0
2
1
4
3
5
7
6
*/
