#include<bits/stdc++.h>
using namespace std;
#define re register
#define il inline
il int read()
{
    re int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=(x<<3)+(x<<1)+(c^48),c=getchar();
    return x*f;
}//�����������ͬѧ��cin���漴��
#define inf 123456789
#define maxn 5005
#define maxm 200005
struct edge
{
	int v,w,next;
}e[maxm<<1];
//ע��������ͼ������������
int head[maxn],dis[maxn],cnt,n,m,tot,now=1,ans;
//�Ѿ�������С�������ĵĵ㵽û�м���ĵ����̾��룬����˵1��2�Žڵ��Ѿ���������С����������ôdis[3]�͵���min(1->3,2->3)
bool vis[maxn];
//��ʽǰ���Ǽӱ�
il void add(int u,int v,int w)
{
	e[++cnt].v=v;
	e[cnt].w=w;
	e[cnt].next=head[u];
	head[u]=cnt;
}
//��������
il void init()
{
    n=read(),m=read();
    for(re int i=1,u,v,w;i<=m;++i)
    {
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
}
il int prim()
{
	//�Ȱ�dis���鸽Ϊ����ֵ
	for(re int i=2;i<=n;++i)
	{
		dis[i]=inf;
	}
    //����Ҫע���رߣ�����Ҫ�õ�min
	for(re int i=head[1];i;i=e[i].next)
	{
		dis[e[i].v]=min(dis[e[i].v],e[i].w);
	}
    while(++tot<n)//��С�������������ڵ���-1
    {
        re int minn=inf;//��minn��Ϊ����ֵ
        vis[now]=1;//��ǵ��Ѿ��߹�
        //ö��ÿһ��û��ʹ�õĵ�
        //�ҳ���Сֵ��Ϊ�±�
        //ע�����ﲻ��ö��now����������ߣ�����1~n
        for(re int i=1;i<=n;++i)
        {
            if(!vis[i]&&minn>dis[i])
            {
                minn=dis[i];
				now=i;
            }
        }
        ans+=minn;
        //ö��now���������ߣ�����dis����
        for(re int i=head[now];i;i=e[i].next)
        {
        	re int v=e[i].v;
        	if(dis[v]>e[i].w&&!vis[v])
        	{
        		dis[v]=e[i].w;
        	}
		}
    }
    return ans;
}
int main()
{
    init();
    printf("%d",prim());
    return 0;
}
