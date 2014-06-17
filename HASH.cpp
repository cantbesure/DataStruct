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
const int inf = ~0U>>4;

int hh[11];

void LineTo(int val,int Nval)
{
    if (hh[Nval%11]==-1)
        hh[Nval%11]=val;
    else
        LineTo(val,Nval+1);
}

void Key(int val)
{
    if (hh[val%11]==-1)
        hh[val%11]=val;
    else
        LineTo(val,val+1);
}

bool findele(int val,int Nval)
{
    if (hh[Nval%11]==-1)
        return false;
    if (hh[Nval%11]==val)
        return true;
    else
        findele(val,Nval+1);
}

int main()
{
    int n,a;
    cout<<"输入数据量（n<12）"<<endl;
    cin>>n;
    memset(hh,-1,sizeof hh);
    cout<<"输入数据"<<endl;
    while (n--)
    {
        cin>>a;
        Key(a);
    }
    cout<<"Hash表如下（-1为空）："<<endl;
    for (int i=0;i<11;i++)
        cout<<i<<":"<<hh[i]<<endl;
    while (1)
    {
        cout<<"请输入查找元素"<<endl;
        int ser;
        cin>>ser;
        if (findele(ser,ser))
            cout<<"找到!"<<endl;
        else
            cout<<"未找到!"<<endl;
    }
}

/*
test data in
7
1
12
23
2
17
56
112
*/

/*
test data out
0:-1
1:1
2:12
3:23
4:2
5:56
6:17
7:112
8:-1
9:-1
10:-1
*/
