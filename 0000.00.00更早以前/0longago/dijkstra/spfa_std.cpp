#include<bits/stdc++.h>
#include<queue>
#include<algorithm>

#define MAXM 100000
#define MAXN 10000

#define INF 1000000000
using namespace std;
struct Edge{
	int v,w,nex;
}E[MAXM];
int tote=0;
int head[MAXN];
void Add_Edge(int u,int v,int w)
{
	tote++;
	E[tote].v=v;
	E[tote].w=w;
	E[tote].nex=head[u];
	head[u]=tote;
}
int dist[MAXN],n;
bool vis[MAXN];
int SPFA(int S/* 起点 */,int T/* 终点 */)
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	dist[S]=0;
	q.push(S);
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=false;
		for(int i=head[u];i;i=E[i].nex)
//		for(int i=0;i<=a[u].size();i++)
		{
			int v=E[i].v;
//			int v=a[u][i];
//			int w=b[u][i];
			if(dist[v]>dist[u]+E[i].w)
			{
				dist[v]=dist[u]+E[i].w;
				if(!vis[v])
				{
					q.push(v);
					vis[v]=true;
				}
			}
		}
	}
	return dist[T];
}
int main(){
	freopen("dijkstra_data.in","r",stdin);
//	freopen("spfa_std.out","w",stdout);
	int n,m;
	int s;//起点 
	int t;//终点 
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);
	}
	printf("%d",SPFA(s,t));
	return 0;
}
