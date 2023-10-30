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
const int MAXM=6e6+1145;
const int MAXN=3e6+1145;
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
bool g[MAXM];
int c[MAXN];
int tarjan(int u,int from,bool root)
{
	low[u]=dfn[u]=++dfs_num;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if((i^1)==from)	continue;
		if(!dfn[v])	
		{
			tarjan(v,i,0),low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])	g[i]=g[i^1]=true;
		}
		else low[u]=min(dfn[v],low[u]);
	}
}
vector<int>ans[MAXN*2];
int dcc=0;
void dfs(int x)
{
	c[x]=dcc;
	if(x)	ans[dcc].push_back(x);
	for(int i=head[x];i;i=edge[i].nxt)
	{
		if(c[v]||g[i])	continue;
		dfs(v);
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
	for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i,0,1);;
	for(int i=1;i<=n;i++)if(!c[i])++dcc,dfs(i);
	printf("%d\n",dcc);
	for(int i=1;i<=dcc;i++)
	{
		printf("%d",ans[i].size());
		for(int j=0;j<ans[i].size();j++)
			printf(" %d",ans[i][j]);
		printf("\n");
	}
	return 0;
}


