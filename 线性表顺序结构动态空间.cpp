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
#define eps 1e-9
#define init 30;
#define increse 10;
using namespace std;
typedef long long LL;

typedef struct   //抽象数据类型
{
    char name[10];
    int num;
    char pos[10];
} employee;


class emplist   //线性表
{
public:
    virtual ~emplist();
    bool Init();
    bool Creat();
    bool Delete(int num);
    void Print();
    emplist();
private:
    employee * emp;
    int amt;
    int listsize;
};

emplist::emplist()
{
    emp=NULL;
    amt=0;
    listsize=0;
}
emplist::~emplist()
{
    if (emp!=NULL) free(emp);
    amt=0;
    listsize=0;
}
bool emplist::Init()  //分配初始空间30
{
    this->emp=(employee *)malloc(30*sizeof(employee));
    if (!this->emp) exit(OVERFLOW);
    this->amt=0;
    this->listsize=30;
    return true;
}
bool emplist::Creat()
{
    //cout<<amt<<listsize<<endl;
    if (this->amt>=this->listsize) //再分配10
    {
        employee *newemp=NULL;
        newemp=(employee *)realloc(this->emp,(this->listsize+10)*sizeof(employee));
        if (!newemp) exit(OVERFLOW);
        this->emp=newemp;
        this->listsize+=increse;
    }
    cin>>emp[amt].name>>emp[amt].num>>emp[amt].pos;
    amt++;
    return true;
}

bool emplist::Delete(int num)
{
    if (!this->amt)
        return false;
    int index=0;
    int flag=true;
    for (; index<this->amt; index++)
        if (this->emp[index].num==num)
        {
            flag=false;
            break;
        }
    if (flag) return false;
    for (; index<this->amt-1; index++)
        this->emp[index]=this->emp[index+1];
    this->amt--;
    return true;
}

void emplist::Print()
{
    if (!this->amt)
    {
        cout<<"No Mem"<<endl;
        return ;
    }
    for (int i=1; i<=this->amt; i++)
        cout<<i<<" "<<this->emp[i-1].name<<" "<<this->emp[i-1].num<<" "<<this->emp[i-1].pos<<endl;
}
int main()
{
    //freopen("in.txt","r",stdin);
    emplist* empl;
    empl=new emplist();
    while (true)
    {
        cout<<"************"<<endl;
        cout<<"*1.InitList*"<<endl;
        cout<<"*2.CreatMem*"<<endl;
        cout<<"*3.DeletMem*"<<endl;
        cout<<"*4.PrintMem*"<<endl;
        cout<<"*5.Exit    *"<<endl;
        cout<<"************"<<endl;
        int opt;
        cin>>opt;
        if (opt==5) break;
        if (opt==1)
        {
            if (empl->Init())
            {
                cout<<"Init Complete!"<<endl;

                //cout<<empl->amt<<empl->listsize<<endl;
                continue;
            }
            else
            {
                cout<<"Init Error!Again"<<endl;
                continue;
            }
        }
        if (opt==2)
        {
//            employee p;
//            cin>>p.name>>p.num>>p.pos;
            if (empl->Creat())
            {
                cout<<"Creat Complete!"<<endl;
                empl->Print();
                continue;
            }
            else
            {
                cout<<"Creat Error!Again"<<endl;
                continue;
            }
        }
        if (opt==3)
        {
            int n;
            cout<<"Plz Input Del Num"<<endl;
            cin>>n;
            if (empl->Delete(n))
            {
                cout<<"Del Complete!"<<endl;
                empl->Print();
                continue;
            }
            else
            {
                cout<<"Nothing Happened"<<endl;
                continue;
            }
        }
        if (opt==4)
        {
            empl->Print();
            continue;
        }
    }
    return 0;
}

