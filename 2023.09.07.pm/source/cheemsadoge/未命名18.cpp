#include<bits/stdc++.h>
using namespace std;
const long long inf=2147483647ll;
const int N=1e6+20;
int tot,head[N],dis[N],vis[N],n,m,s;
struct Edge
{
	int next,to,dis; 
}edge[N];
void addedge(int u,int v,int val)
{
	tot++;
	edge[tot].next=head[u];
	edge[tot].dis=val;
	edge[tot].to=v;
	head[u]=tot;
} 
void spfa()
{
	queue<int> q;
	for(int i=1; i<=n; i++) 
	{
		dis[i]=inf;
		vis[i]=0;
	}
	  q.push(s); dis[s]=0; vis[s]=1;
  while(!q.empty())
  {
    int u=q.front();
    q.pop(); vis[u]=0;
    for(int i=head[u]; i; i=edge[i].next)
    {
      int v=edge[i].to; 
      if(dis[v]>dis[u]+edge[i].dis)
      {
        dis[v]=dis[u]+edge[i].dis;
        if(vis[v]==0)
        {
          vis[v]=1;
          q.push(v);
        }
      }
    }
  }
}
int main()
{
	  cin>>n>>m>>s;
  	for(int i=1; i<=m; i++)
  	{
   	 int f,g,w;
   		cin>>f>>g>>w; 
   		addedge(f,g,w);
  }
  spfa();
  for(int i=1; i<=n; i++)
    if(s==i) cout<<0<<" ";
      else cout<<dis[i]<<" ";
  return 0;
} 
