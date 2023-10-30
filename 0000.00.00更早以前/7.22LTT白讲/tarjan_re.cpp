#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e6+1145;
struct Edge{
	int u,v,nxt,val;
}edge[MAXN];
int totr=1,head[MAXN];
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
}
int dfn[MAXN],dfs_num=0;
int low[MAXN];
void tarjan(int u,int from)
{
	dfn[u]=low[u]=++dfs_num;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if((i^1)==from)	continue;
		if(!dfn[v])	tarjan(v,i),low[u]=min(low[u],low[v]);
		else	low[u]=min(low[u],dfn[v]);
		#undef v
	}
}

int main()
{
	return 0;
}
