/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n');
#define pk putchar(' ');
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,nxt;
}edge[MAXN*2];
int head[MAXN],totr;
void add_edge(int u,int v)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	head[u]=totr;
}
int siz[MAXN],val[MAXN];
int n,sum,ans,res;
priority_queue<int>centroid;
void dfs(int u,int fa)
{
	if(res) return ;
	siz[u]=val[u];int cnt=0;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(v==fa) continue; 
		dfs(v,u);
		if(res) return ;
		siz[u]+=siz[v];
		cnt=max(cnt,siz[v]);
		#undef v
	}
	cnt=max(cnt,sum-siz[u]);
	if(cnt<=sum/2) res=u;
}
void dfs2(int u,int dep,int fa)
{
	ans+=dep*val[u];
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(v==fa) continue;
		dfs2(v,dep+1,u);
		#undef v
	}
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	int u,v;
	read(n);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);
		add_edge(u,v);add_edge(v,u);
	}
	for(int i=1;i<=n;i++)
	{
		read(val[i]);
		sum+=val[i];
	}
	dfs(1,-1);
//	write(res);pc;
	dfs2(res,0,-1);
	write(ans);
}
