#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1145;
struct Edge{
	int v,val,nxt;
}edge[MAXN*4];
int head[MAXN],totr;
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
long long n,m,p;
int cnt[MAXN],dis[MAXN],vis[MAXN];
#define v edge[i].v
void SPFA()
{
	queue<int>a;
	a.push(0);
	vis[0]=1;
	dis[0]=0;
	while(!a.empty())
	{
		int u=a.front();
		a.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].nxt)
			if(dis[u]+edge[i].val<dis[v])
			{
				dis[v]=dis[u]+edge[i].val;
				if(!vis[v])
				{
					a.push(v);
					vis[v]=true;
					cnt[v]=cnt[u]+1;
					if(cnt[v]>=n+1)
					{
						printf("NO");
						exit(0);
					}
				}
			}
	}
}


int main()
{
	int a,b,c;
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) add_edge(0,i,0);
    for(int i=1;i<=m;i++)
    {
    	scanf("%d%d%d",&a,&b,&c);
    	add_edge(b,a,c);
	}
    memset(dis,0x3f,sizeof(dis));
    SPFA();
    for(int i=1;i<=n;i++)
    	printf("%d ",dis[i]);
}
