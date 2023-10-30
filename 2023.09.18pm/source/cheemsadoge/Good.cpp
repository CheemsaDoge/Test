/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e5+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("good.in","r",stdin);
//	freopen("good.out","w",stdout);
//}
struct Edge{
	int u,v,w,nxt;
}edge[MAXM];
int totr,head[MAXN];
inline void add_edge(int u,int v,int w)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].w=w;
	head[u]=totr;
}
int T[7],tT[7];
int dis[MAXN];
int dist[7][7];
struct DisforDj{
	int u,dis;
	bool operator <(const DisforDj b) const
	{
		return dis>b.dis;
	}
};
int n,m;
int ed[MAXN];
priority_queue<DisforDj>que;
void Dij(int u)
{
	int st=u;
	DisforDj t;
	fill(dis,dis+n+1,INF);
	dis[u]=0;
	que.push((DisforDj){u,dis[u]});
	while(!que.empty())
	{
		t=que.top();que.pop();
		u=t.u;
		if(t.dis>dis[u]) continue;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(dis[v]>dis[u]+edge[i].w)
			{
				dis[v]=dis[u]+edge[i].w;
				que.push((DisforDj){v,dis[v]});
				if(ed[v]) dist[ed[st]][ed[v]]=dis[v];
			}
			
		}
	}
}
int main(){
//	_File();
	read(n),read(m);
	int tot=0;
	for(int i=1;i<=5;i++)
		read(T[i]),ed[T[i]]=i,tT[i]=i;
	T[0]=1;ed[1]=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		read(u);read(v);read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=0;i<=5;i++) Dij(T[i]);
	int sum=0,ans=INF;
	for(int i=0;i<=4;i++)
		sum+=dist[i][i+1];
	ans=min(ans,sum);
	while(next_permutation(tT+1,tT+6))
	{
		sum=0;
		for(int i=0;i<=4;i++)
			sum+=dist[tT[i]][tT[i+1]];	
		ans=min(ans,sum);
	}
	write(ans);
	return 0;
}


