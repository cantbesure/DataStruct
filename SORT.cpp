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

int seq[100+10];//����
int tmp[100+10];//�鲢����������


//�۰����
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
        else //���ֹ���
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
			//����
            for (int i=cnt-1; i>r; i--)
                seq[i+1]=seq[i];
            seq[r+1]=num;
        }

    }
    for (int i=1; i<n; i++)
        cout<<seq[i]<<" ";
    cout<<seq[n]<<endl;
}

//ð������
void BubSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
		//��������Ƿ����Ҫ��
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

//����
int QuSort_Part(int l,int r)
{
    int index=l;
    int cmp=seq[index];//��־ֵ
    swap(seq[index],seq[r]);
	//�Ƚϱ�־ֵ��������
    for (int i=l; i<r; i++)
    {
        if (seq[i]<cmp)
            swap(seq[index++],seq[i]);
    }
    swap(seq[index],seq[r]);
	//���ر��λ��
    return index;
}

void QuSort_Out(int l,int r)
{
    if (l>=r)
        return ;
    int index=QuSort_Part(l,r);
	//�ӱ��λ�÷ֱ��������ҵݹ�
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

//��ѡ������

void SelSort(int n)
{
    int nn=inf;
    int index;
	//���뼴�������Сֵ
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
	//�����ÿ�ε���Сֵ
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

//�鲢����

void MergeSort_Part(int l,int r)
{
    if (r-l>1)
    {
        //�м�λ�ñ�ǣ��Ƚ������Ҳ��ֵ���Сֵ��˳�����tmp������
		int mid=(l+r)>>1;
        int p=l,q=mid,i=l;
		//�ݹ鱣֤���Ҳ��ֱַ���˳������
        MergeSort_Part(l,mid);
        MergeSort_Part(mid,r);
        while (p<mid||q<r)
        {
            if (q>=r||(p<mid && seq[p]<=seq[q]))
                tmp[i++]=seq[p++];
            else
                tmp[i++]=seq[q++];
        }
		//��tmp����ֵ�Ż�seq
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


//����

void HeapSort_Part(int index,int len)
{
    int i=index;
	//ȡ������
    int left=i<<1;
    while (left<len)
    {
		//�Ƚ�����������С��ѡ����
        if (seq[left]<seq[left+1])
            left++;
		//�͸��ڵ�Ƚϴ�С�������ڸ��ڵ㣬����
        if (seq[i]>seq[left])
            break;
        else
        {
            swap(seq[i],seq[left]);
			//��������������ӽڵ�Ϊ���ڵ��֦Ҷ�Ƿ���ϴ󶥶�Ҫ��
            i=left;
            left=i<<1;
        }
    }
}

void HeapSort(int n)
{
    for (int i=1; i<=n; i++)
        cin>>seq[i];
		//���մ����ı�seq�ṹ����ʱ����Ϊ���ֵ
		//ȥ��һ����Ҷ�ӽڵ㼴��n-1��/2
    for (int i=(n-1)>>1; i>=1; i--)
        HeapSort_Part(i,n);
		
	//�������ú󣬶�ǰn-i�����ж��ţ�n-2ʱ�������
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
        cout<<"1.�۰��������"<<endl;
        cout<<"2.ð������"<<endl;
        cout<<"3.��������"<<endl;
        cout<<"4.��ѡ������"<<endl;
        cout<<"5.�鲢����"<<endl;
        cout<<"6.������"<<endl;
        cout<<"0.�˳�"<<endl;
        int k;
        cin>>k;
        if (!k) break;
        int n;
        memset(seq,-1,sizeof seq);
        memset(tmp,-1,sizeof tmp);
        cout<<"��������������<=100��"<<endl;
        cin>>n;
        cout<<"����������"<<endl;
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
