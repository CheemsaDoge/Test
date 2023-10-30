#include<bits/stdc++.h>
#include<queue>
#include<algorithm>

#define MAXM 100000
#define MAXN 10000

#define INF 1000000000
using namespace std;
/****************************/
//前向星建图 
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
/****************************/

int dist[MAXN],n;
bool vis[MAXN];


/****************************/
//使用优先队列作为堆优化 
struct Node{
	int dist;
	int num;
};
//重载运算符以实现优先队列 
bool operator <( Node a,Node b)
{
	return a.dist>b.dist;
}
//定义优先队列 
priority_queue<Node>q;


/****************************/
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
		vis[u.num]=false; 
		for(int i=head[u.num];i;i=E[i].nex)
		{
			int v=E[i].v;
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

/********/

int main(){
	freopen("dijkstra_data.in","r",stdin);
//	freopen("dijkstra_std.out","w",stdout);
	int m;
	int s;//起点 
	int t;//终点 
	
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Add_Edge(u,v,w);
	}
	printf("%d\n",dijkstra(s,t));
	return 0;
}
/*
6 7 1 5
1 2 7
1 3 3
2 4 8
2 5 1
3 5 4
4 6 9
5 6 2
*/
