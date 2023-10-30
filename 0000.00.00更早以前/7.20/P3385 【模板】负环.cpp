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
void initialize(int n,int m)
{
	memset(cnt,0,sizeof(cnt));
	memset(dis,0,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	totr=0;
}
#define v edge[i].v
void SPFA()
{
	queue<int>a;
	a.push(1);
	vis[1]=1;
	dis[1]=0;
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
					vis[v]=true;
					cnt[v]=cnt[u]+1;
					a.push(v);
					if(cnt[v]>n+1)
					{
						printf("YES\n");
						return;
					}
				}
			}
	}
	printf("NO\n");
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
	    scanf("%lld%lld",&n,&m);
	    initialize(n,m);
//	    for(int i=1;i<=n;i++) add_edge(0,i,0);
	    for(int i=1;i<=m;i++)
	    {
	    	scanf("%d%d%d",&a,&b,&c);
	    	if(c>=0)
	    	{
		    	add_edge(b,a,c);
		    	add_edge(a,b,c);
			}
			else
				add_edge(a,b,c);
		}
	    memset(dis,0x3f,sizeof(dis));
	    SPFA();
	}
}
