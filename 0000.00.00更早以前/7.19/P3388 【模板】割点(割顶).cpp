#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
#define ul unsigned long long
int n,m;
const int MAXM=1e5+1145;
const int MAXN=2e4+1145;
struct Edge{
	int u,v,val,nxt;
}edge[MAXM*4];
int head[MAXN],totr=1;
void add_edge(int u,int v,int val){
	edge[++totr].val=val;
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int tot=0;
#define v (edge[i].v)
int dfn[MAXN],dfs_num=0,low[MAXN];
bool st[MAXN];
int dfs(int u,int from,bool root)
{
	int child=0;
	low[u]=dfn[u]=++dfs_num;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if((i^1)==from)	continue;
		if(!dfn[v])	
		{
			child++,dfs(v,i,0),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&(!root))	tot+=!st[u],st[u]=true;
		}
		else low[u]=min(dfn[v],low[u]);
	}
	if(root&&child>=2)
	{
		tot+=!st[u];
		st[u]=true;
	}
}
int main()
{
	ri x,y;
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);
		add_edge(x,y,1);add_edge(y,x,1);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i,0,1);
	printf("%d\n",tot);
	for(int i=1;i<=n;i++)if(st[i])printf("%d ",i);
}


