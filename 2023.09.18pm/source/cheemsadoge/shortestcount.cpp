/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=2e5+11145;const int INF=2147483646ll;//2^31-1
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
int dis[MAXN],siz[MAXN];
struct DisforDj{
//	private:
//	public:
	int u,dis;
	bool operator <(const DisforDj a) const {
		return dis>a.dis;
	}
};
int n,m;
priority_queue<DisforDj>que;
inline void Dijkstra() {
	fill(dis,dis+1+n,INF);
	dis[1]=0;siz[1]=1;
	int u=1;DisforDj t;
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
				siz[v]=siz[u]%100003;
			}
			else if(dis[v]==dis[u]+edge[i].w) siz[v]+=siz[u],siz[v]%=100003;
		}
	}
}
int main(){
//	_File();
	read(n),read(m);
	for(int i=1;i<=m;i++){
		int u,v;
		read(u);read(v);
		add_edge(u,v,1);
		add_edge(v,u,1);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
		write(siz[i]%100003),pc;
	return 0;
}


