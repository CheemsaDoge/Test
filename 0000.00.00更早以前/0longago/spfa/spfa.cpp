#include <bits/stdc++.h>
using namespace std;
#define INF 10000086
const int N=1e6+1145;
int tot,dis[N],vis[N];
int n,m;
queue<int>a;
struct edget
{
	int to;
	int nxt;
	int val;
}edge[N];
int head[N];
void add_edge(int u,int v,int val)
{
	tot++;
	edge[tot].to=v;
	edge[tot].nxt=head[u];
	head[u]=tot;
	edge[tot].val=val;
}
void spfa()
{
	int b=a.front();
	while(!a.empty())
	{
		b=a.front();
		vis[b]=0;
		a.pop();
		for(int i=head[b];i;i=edge[i].nxt)
		{
			int y=edge[i].to;
			int z=edge[i].val;
			if(dis[y]>dis[b]+z)
			{
				dis[y]=dis[b]+z;
				if(!vis[y])	a.push(y),vis[y]=1;
			}
		}
	}
//	if(b==n)
//		return;
//	int c=head[b];
//	if(dis[edge[c].to]>dis[b]+edge[c].val)
//		dis[edge[c].to]=dis[b]+edge[c].val;
//	while(edge[c].nxt!=0)
//	{
//		c=edge[c].nxt;
//		if(dis[edge[c].to]>dis[b]+edge[c].val)
//			dis[edge[c].to]=dis[b]+edge[c].val;
//		if(!vis[edge[c].to])
//			a.push(edge[c].to);
//		vis[edge[c].to]=1;
//	}
//	if(!a.empty())
//		bfs();
}

int main()
{
	freopen("spfa_data.in","r",stdin);
	freopen("spfa_data.out","w",stdout);
	int x,y,z;
	scanf("%d%d",&n,&m);
	a.push(1);
	for(int i=1;i<=n;i++)
		dis[i]=INF;	
	dis[1]=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
	}
	spfa();
	printf("%d",dis[n]);
}
