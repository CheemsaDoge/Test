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
int low[MAXN],dfn[MAXN],dfs_num=0,sd,val[MAXN];
void tarjan(int u)
{
	low[u]=dfn[u]=++dfs_num;
	stac[++tot]=u;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(!dfn[v])
		{
			dfs(v);
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
			
			if(u==y) break;
			val[u]+=val[y];
		}
	}
}
int main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	int n;
	read(n);
	char x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n+1;j++)
			if(getchar()-'0'==1)
				add_edge(i,j);
	register long long res=0;
	
	printf("%lld\n",res);
}
