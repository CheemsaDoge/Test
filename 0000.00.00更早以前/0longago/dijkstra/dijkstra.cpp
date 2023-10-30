#include <bits/stdc++.h>
using namespace std;
#define INF 1000000000
const int N=1e6+1145;
int tot,dis[N],vis[N];
int n,m;
struct single
{
	int num;
	int val;
};
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
bool operator <(const single &a,const single &b)
{
	return a.val>b.val;
}
priority_queue<single>a;
void dijkstra(int s,int e)
{
	dis[s]=0;
	single t;
	t.num=s;
	t.val=0;
	a.push(t);
	for(int i=1;i<=n;i++)
	{
//		while(vis[a.top().num]&&!a.empty())
//			a.pop();
		t=a.top();
//		vis[t.num]=true; 
		for(int j=head[t.num];j;j=edge[j].nxt)
		{
			int v=edge[j].to;
			if(dis[v]>dis[t.num]+edge[j].val)
			{
				dis[v]=dis[t.num]+edge[j].val;
				single p;
				p.num=v;
				p.val=dis[v];
				a.push(p);
			}
		}
	}
}
int main()
{
	freopen("dijkstra_data.in","r",stdin);
	freopen("dijkstra_data.out","w",stdout);
	int x,y,z;
	int s,e;
	scanf("%d%d%d%d",&n,&m,&s,&e);
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	while(m--)
	{
		scanf("%d%d%d",&x,&y,&z);
		add_edge(x,y,z);
	}
	dijkstra(s,e);
	printf("%d",dis[e]);
}
