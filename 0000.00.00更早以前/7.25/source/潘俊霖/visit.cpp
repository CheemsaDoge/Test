#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int MAXN=5e4+1145;
const int MAXM=1e5+1145;
#define ll long long
#define ri register int
#define rl register long long
int head[MAXN],totr;
struct Edge{
	int u,v,val,nxt;
}edge[MAXM*4];
void add_edge(int u,int v,int val)
{
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int dis[MAXN],vis[MAXN];
void SPFA(int u)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>a;
	a.push(u);
	dis[u]=0;
	while(!a.empty())
	{
		u=a.front();a.pop();
		vis[u]=0;
		#define v (edge[i].v)
		#define val (edge[i].val)
		for(int i=head[u];i;i=edge[i].nxt)
		{
			if(dis[v]>dis[u]+val)
			{
				dis[v]=dis[u]+val;
				if(!vis[v]) a.push(v),vis[v]=1;
			}
		}
		#undef val
		#undef v
	}
}
int n,m,x,y,z;
int a[8];
int fdis[8][8];
ll ans=9223372036854775804ll;
int main() {
	freopen("visit.in","r",stdin);
	freopen("visit.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=5;i++)
		read(a[i]);
	a[0]=1;
	for(int i=1;i<=m;i++)
	{
		read(x);read(y);read(z);
		add_edge(x,y,z);
		add_edge(y,x,z);
	}
	for(int i=0;i<=5;i++)
	{
		SPFA(a[i]);
		for(int j=0;j<=5;j++)
			fdis[i][j]=dis[a[j]];
	}
	ll val;
	int b[8];
	b[5]=5;
	b[1]=1;
	b[2]=2;
	b[3]=3;
	b[4]=4;
	b[0]=0;
	while(next_permutation(b+1,b+6))
	{
		val=0;
		for(int i=0;i<=4;i++)
		{
			val+=fdis[b[i]][b[1+i]];
			if(val>ans) break;
		}
		ans=min(val,ans);
	}
 printf("%lld",ans);
}
/*救救孩子，放过SPFA
关于SPFA
·它活了
*/
