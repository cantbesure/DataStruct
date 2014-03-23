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

int cir_q[LMT]={0,0,0,1};
int ff=0,rr=3;//循环队列的数据起始为满
int f[100]={0,0,0,1};

void push(int data)
{
    if ((rr+1)%LMT==ff)
        return ;
    cir_q[(rr+1)%LMT]=data;
    rr=(rr+1)%LMT;
}

void pop()
{
    if (ff==rr)
        return ;
    ff=(ff+1)%LMT;
}

int head()
{
    if (ff==rr)
        return 0;
    return cir_q[ff];
}


int main()
{
    for (int i=4;i<maxx;i++)
    {
        int sum=0;
        for (int j=0;j<4;j++)
            sum+=cir_q[j];
        f[i]=sum;
        pop();
        push(sum);
        if (f[i-1]<=200&&f[i]>200)
        {
            cout<<i-1<<endl;
            break;
        }

    }
    return 0;
}
