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

int seq[100+10];//序列
int tmp[100+10];//归并排序辅助数组


//折半插入
void BiInSort(int n)
{
    int cnt=0;
    for (int i=1; i<=n; i++)
    {
        int num;
        cin>>num;
        if (cnt==0)
        {
            seq[1]=num;
            cnt++;
        }
        else //二分过程
        {
            int l=1;
            int r=cnt++;
            int mid=(l+r)>>1;
            while (l<=r)
            {
                mid=(l+r)>>1;
                if (seq[mid]<=num)
                    l=mid+1;
                else if (seq[mid]>num)
                    r=mid-1;
            }
			//后移
            for (int i=cnt-1; i>r; i--)
                seq[i+1]=seq[i];
            seq[r+1]=num;
        }

    }
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

//冒泡排序
void BubSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
		//标记序列是否符合要求
    int flag=true;
    while (flag)
    {
        flag=false;
        for (int i=1; i<n; i++)
        {
            if (seq[i]>seq[i+1])
            {
                if (!flag) flag=true;
                swap(seq[i],seq[i+1]);
            }
        }
    }
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

//快排
int QuSort_Part(int l,int r)
{
    int index=l;
    int cmp=seq[index];//标志值
    swap(seq[index],seq[r]);
	//比较标志值划分左右
    for (int i=l; i<r; i++)
    {
        if (seq[i]<cmp)
            swap(seq[index++],seq[i]);
    }
    swap(seq[index],seq[r]);
	//返回标记位置
    return index;
}

void QuSort_Out(int l,int r)
{
    if (l>=r)
        return ;
    int index=QuSort_Part(l,r);
	//从标记位置分别向左向右递归
    QuSort_Out(l,index-1);
    QuSort_Out(index+1,r);
}

void QuSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
    QuSort_Out(1,n);
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

//简单选择排序

void SelSort(int n)
{
    int nn=inf;
    int index;
	//输入即处理出最小值
    for (int i=1; i<=n; i++)
    {
        cin>>seq[i];
        if (nn>seq[i])
        {
            nn=seq[i];
            index=i;
        }
    }
    swap(seq[1],seq[index]);
	//处理出每次的最小值
    for (int i=2; i<n; i++)
    {
        nn=seq[i];
        index=i;
        for (int j=i+1; j<=n; j++)
        {
            if (nn>seq[j])
            {
                nn=seq[j];
                index=j;
            }
        }
        swap(seq[i],seq[index]);
    }
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

//归并排序

void MergeSort_Part(int l,int r)
{
    if (r-l>1)
    {
        //中间位置标记，比较其左右部分的最小值按顺序放入tmp数组中
		int mid=(l+r)>>1;
        int p=l,q=mid,i=l;
		//递归保证左右部分分别按照顺序排列
        MergeSort_Part(l,mid);
        MergeSort_Part(mid,r);
        while (p<mid||q<r)
        {
            if (q>=r||(p<mid && seq[p]<=seq[q]))
                tmp[i++]=seq[p++];
            else
                tmp[i++]=seq[q++];
        }
		//将tmp数组值放回seq
        for (i=l; i<r; i++)
            seq[i]=tmp[i];
    }
}

void MergeSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
    MergeSort_Part(1,n+1);
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}


//堆排

void HeapSort_Part(int index,int len)
{
    int i=index;
	//取左子树
    int left=i<<1;
    while (left<len)
    {
		//比较左右子树大小，选择大的
        if (seq[left]<seq[left+1])
            left++;
		//和父节点比较大小，若大于父节点，交换
        if (seq[i]>seq[left])
            break;
        else
        {
            swap(seq[i],seq[left]);
			//交换后需检验其子节点为父节点的枝叶是否符合大顶堆要求
            i=left;
            left=i<<1;
        }
    }
}

void HeapSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
		//按照大顶树改变seq结构，此时顶端为最大值
		//去第一个非叶子节点即（n-1）/2
    for (int i=(n-1)>>1; i>=1; i--)
        HeapSort_Part(i,n);
		
	//将顶端置后，对前n-i个进行堆排，n-2时完成排序
    for (int i=1; i<n-1; i++)
    {
        swap(seq[1],seq[n+1-i]);
        HeapSort_Part(1,n-i);
    }
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

int main()
{
    while (1)
    {
        cout<<"1.折半插入排序"<<endl;
        cout<<"2.冒泡排序"<<endl;
        cout<<"3.快速排序"<<endl;
        cout<<"4.简单选择排序"<<endl;
        cout<<"5.归并排序"<<endl;
        cout<<"6.堆排序"<<endl;
        cout<<"0.退出"<<endl;
        int k;
        cin>>k;
        if (!k) break;
        int n;
        memset(seq,-1,sizeof seq);
        memset(tmp,-1,sizeof tmp);
        cout<<"请输入数据量（<=100）"<<endl;
        cin>>n;
        cout<<"请输入数据"<<endl;
        switch (k)
        {
        case 1:
            BiInSort(n);
            break;
        case 2:
            BubSort(n);
            break;
        case 3:
            QuSort(n);
            break;
        case 4:
            SelSort(n);
            break;
        case 5:
            MergeSort(n);
            break;
        case 6:
            HeapSort(n);
            break;
        }
    }
    return 0;

}


/*
test data in

*/

/*
test data out

*/
