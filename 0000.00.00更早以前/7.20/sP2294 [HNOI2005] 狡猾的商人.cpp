#include<queue>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1100
using namespace std;
inline void read(int &x)
{
    x=0;
    int p=1;
    char c=getchar();
    while(!isdigit(c)){if(c=='-')p=-1;c=getchar();}
    while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^'0');c=getchar();}
    x*=p;

}//���ٶ���

int n,m;
struct node
{
    int l,r,s;
    bool operator < (const node &h)const
    {
        if(l!=h.l)return l>h.l;
        return r>h.r;

}//�����������ȷ�����ȶ��е����ȼ�

}tmp;
priority_queue<node>q;
int main()
{
    int t;
    read(t);
    while(t--)
    {    
        while (!q.empty()) q.pop();//�����������
        read(n);read(m);
        if(m==1){printf("true\n");continue;}//��ʵû��Ҫ���У�ֻ���Ż�һ���
        for(int i=1;i<=m;i++)
        {
            int l,r,s;
            read(tmp.l);read(tmp.r);read(tmp.s);
            q.push(tmp);
        }
        tmp=q.top();//ȡ����һ��
        q.pop();
        while(!q.empty())
        {    
            node tmp1;
            tmp1=q.top();
            q.pop();
            if(tmp.l==tmp1.l)
            {
                if(tmp.r==tmp1.r)
                {
                    if(tmp.s!=tmp1.s)
                    {printf("false\n");goto end;}//�˳�����ѭ����С����
                }
                else 
                if(tmp.r<tmp1.r)
                    q.push((node) {tmp.r+1, tmp1.r, tmp1.s - tmp.s});//��������Ĳ��ַ������
            }
            tmp = tmp1;//������
        }
        printf("true\n");
        end:;
    }
    return 0;
}
