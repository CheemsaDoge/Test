#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN = 1e6+1145;
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
int tot;
int head[MAXN];
struct Edge{
	int v;
	int nxt;
}edge[MAXN];
void add_edge(int u,int v){
	tot++;
	edge[tot].nxt=head[u];
	edge[tot].v=v;
	head[u]=tot;
}
int hson[MAXN];
int dep[MAXN];
int fa[MAXN];
int size[MAXN];
int top[MAXN];
//int Initialize(int u,int deep)
//{
//	hson[u]=0;
//	dep[u]=deep+1;
//	size[u]=1;
//	for(int i=head[u];i!=0;i=edge[i].nxt)
//	{
//		if(fa[u]!=edge[i].v)
//		{
//			size[u]+=Initialize(edge[i].v,deep);
//			fa[edge[i].v]=u;
//			if(size[hson[u]]<size[edge[i].v])
//				hson[u]=edge[i].v;
//		}
//	}
//	return size[u];
//}
int dfs1(int x){
	size[x]=1;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v!=fa[x])
		{
			fa[v]=x;
			dep[v]=dep[x]+1;
			dfs1(v);
			size[x]+=size[v];
			if(size[hson[x]]<size[v])
				hson[x]=v;
		}
	}
}
int dfs2(int x)
{
	if(x==hson[fa[x]])
		top[x]=top[fa[x]];
	else
		top[x]=x;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v!=fa[x])
			dfs2(v);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=fa[top[x]];
	}
		if(dep[x]<dep[y])
		return x;
	return y;
}

int main()
{
	int n,m,s;
	n=read();
	m=read();
	s=read();
	int x,y;
	for(int i=1;i<=n-1;i++)
	{
		x=read();
		y=read();
		add_edge(x,y);
		add_edge(y,x);
	}
	dfs1(s);
	dfs2(s);
	for(int i=1;i<=m;i++)
	{
		x=read();
		y=read();
		printf("%d\n",LCA(x,y));
	}
}
