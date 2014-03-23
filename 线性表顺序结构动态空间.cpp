#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstring>
#define eps 1e-9
#define init 30;
#define increse 10;
using namespace std;
typedef long long LL;

typedef struct   //������������
{
    char name[10];
    int num;
    char pos[10];
} employee;


class emplist   //���Ա�
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
bool emplist::Init()  //�����ʼ�ռ�30
{
    this->emp=(employee *)malloc(30*sizeof(employee));
    if (!this->emp) exit(0);
    this->amt=0;
    this->listsize=30;
    return true;
}
bool emplist::Creat()
{
    //cout<<amt<<listsize<<endl;
    if (this->amt>=this->listsize) //�ٷ���10
    {
        employee *newemp=NULL;
        newemp=(employee *)realloc(this->emp,(this->listsize+10)*sizeof(employee));
        if (!newemp) exit(0);
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
        cout<<"û����"<<endl;
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
        cout<<"**************"<<endl;
        cout<<"*1.��ʼ������*"<<endl;
        cout<<"*2.�����Ա  *"<<endl;
        cout<<"*3.ɾ����Ա  *"<<endl;
        cout<<"*4.��ӡ��Ա  *"<<endl;
        cout<<"*5.�˳�      *"<<endl;
        cout<<"**************"<<endl;
        int opt;
        cin>>opt;
        if (opt==5) break;
        if (opt==1)
        {
            if (empl->Init())
            {
                cout<<"��ʼ���ɹ�!"<<endl;

                //cout<<empl->amt<<empl->listsize<<endl;
                continue;
            }
            else
            {
                cout<<"��ʼ��ʧ�ܣ�"<<endl;
                continue;
            }
        }
        if (opt==2)
        {
//            employee p;
//            cin>>p.name>>p.num>>p.pos;
            if (empl->Creat())
            {
                cout<<"�����ɹ�!"<<endl;
                empl->Print();
                continue;
            }
            else
            {
                cout<<"����ʧ�ܣ�"<<endl;
                continue;
            }
        }
        if (opt==3)
        {
            int n;
            cout<<"������ɾ������Ա���"<<endl;
            cin>>n;
            if (empl->Delete(n))
            {
                cout<<"ɾ���ɹ�!"<<endl;
                empl->Print();
                continue;
            }
            else
            {
                cout<<"ʲô��û�з���"<<endl;
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

