/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n');
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXN*2];
int head[MAXN],totr;
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
bool vis[MAXN];
int d[MAXN],ans;
//int num[MAXN],res;
void dp(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(vis[v]) continue;
		dp(v);
//		if(d[u]+d[v]+edge[i].val>ans) res=num[u]+num[v]+1;
		ans=max(ans,d[u]+d[v]+edge[i].val);
//		if(d[u]<d[v]+edge[i].val) num[u]=num[v]+1;
		d[u]=max(d[u],d[v]+edge[i].val);
		#undef v
	}
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("longest.in","r",stdin);
	freopen("longest.out","w",stdout);
	int n,u,v,w;
	read(n);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);read(w);
		add_edge(u,v,w);add_edge(v,u,w);
	}
	dp(1);
	write(ans);
//	pc;
//	write(res);
}
