#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
const int MAXN=1e5+1145;
int ans=0;
struct Edge{
	int v;
	int nxt;
	bool p;	
}edge[MAXN];
bool dfn[2000];
int n,m,e;
int tot=1;
int head[2000];
void add_edge(int u,int v,bool p)
{
	tot++;
	edge[tot].nxt=head[u];
	head[u]=tot;
	edge[tot].v=v;
	edge[tot].p=p;
}
bool vis[2000];
bool dfs(int x)
{
	if(x>n)
		if(!vis[x-n])
		{
			vis[x-n]=true;
			return true;
		}
	for(int i=head[x];i;i=edge[i].nxt)
	{
		if(edge[i].p&&!dfn[x])
		{
			dfn[x]=true;
			bool a=dfs(edge[i].v);
			dfn[x]=false;
			if(a)
			{
				edge[i].p=0;
				edge[i^1].p=1;
				return true;
			}
		}
	}
	return 0;
}
int main()
{
	int a,b;
	n=read();m=read();e=read();
	for(int i=1;i<=e;i++)
	{
		a=read();b=read();
		add_edge(a,b+n,1);
		add_edge(b+n,a,0);
	}
	for(int i=1;i<=n;i++)
		ans+=dfs(i)?1:0;
	printf("%d",ans);
}
