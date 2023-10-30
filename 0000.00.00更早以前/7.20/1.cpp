#include <bits/stdc++.h>
using namespace std;

template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
const int MAXM=6e6+1145;
const int MAXN=6e6+1145;
struct Edge{
	int u,v,nxt;
}edge[MAXM*4];
int head[MAXN],totr=1;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
bool vis[MAXN];
#define v (edge[i].v)
int tot=0;
int sum,stac[MAXN];
int low[MAXN],dfn[MAXN],dfs_num=0,sd[MAXN],val[MAXN],rd[MAXN];
void tarjan(int u)
{
	low[u]=dfn[u]=++dfs_num;
	stac[++tot]=u;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else	low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		int y;
		while(y=stac[tot--])
		{
			sd[y]=u;
			vis[y]=0;
			if(u==y) break;
			val[u]+=val[y];
		}
	}
}
int dist[MAXN];
int m,n;
Edge ed[MAXN];
#undef	v
int topo()
{
	queue<int>a;
	for(int i=1;i<=n;i++)
		if(sd[i]==i&&!rd[i])
		{
			a.push(i);
			dist[i]=val[i];
		}
	while(!a.empty())
	{
		int k=a.front();a.pop();
		for(int i=head[k];i;i=ed[i].nxt)
		{
			dist[ed[i].v]=max(dist[ed[i].v],dist[k]+val[ed[i].v]);
			rd[ed[i].v]--;
			if(!rd[ed[i].v]) a.push(ed[i].v);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,dist[i]);
	return ans;
	
}
int main()
{
//	freopen("classroom.in","r",stdin);
//	freopen("classroom.out","w",stdout);
	read(n);
	read(m);
	int x,y;
	for(int i=1;i<=n;i++)
		read(val[i]);
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);
		add_edge(x,y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])	tarjan(i);
	int s=0;
	for(int i=1;i<=m;i++)
	{
		int x=sd[edge[i].u],y=sd[edge[i].v];
		if (x!=y)
		{
			ed[++s].nxt=head[x];
			ed[s].v=y;
			ed[s].u=x;
			head[x]=s;
			rd[y]++;
		}
	}
	printf("%d",topo());
}
