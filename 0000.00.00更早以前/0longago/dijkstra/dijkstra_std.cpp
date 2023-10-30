#include<bits/stdc++.h>
#include<queue>
#include<algorithm>
#define MAXN 1000000
#define INF 1000000000
using namespace std;
struct Edge{
	int v,w,nex;
}E[MAXN];
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
struct Node{
	int dist;
	int num;
};
bool operator <( Node a,Node b)
{
	return a.dist>b.dist;
}
priority_queue<Node>q;


int dijkstra(int S,int T){
	for(int i=1;i<=n;i++)
		dist[i]=INF;
	dist[S]=0;
	
	Node u;
	u.num=S;
	u.dist=0;
	
	q.push(u);
	for(int j=1;j<=n;j++)
	{
		while(vis[q.top().num]&&!q.empty()){
			q.pop();
		}
		u=q.top();
		vis[u.num]=true; 
		for(int i=head[u.num];i;i=E[i].nex)
//		for(int i=0;i<a[u.num].size();i++)
		{
			int v=E[i].v;
//			int v=a[u.num][i];
//			int w=b[u.num][i];
			if(dist[v]>dist[u.num]+E[i].w)
			{
				dist[v]=dist[u.num]+E[i].w;
				Node p;
				p.num=v;
				p.dist=dist[v];
				q.push(p);
			}
		}
			
	}
	return dist[T];
}

int main(){
	freopen("dijkstra_data.in","r",stdin);
	freopen("dijkstra_std.out","w",stdout);
	int s;//Æðµã 
	int t;//ÖÕµã 
	int m;
	int u,v,w;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);
	}
	printf("%d",dijkstra(s,t));
	return 0;
}
