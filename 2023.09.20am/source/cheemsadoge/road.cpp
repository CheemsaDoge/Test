/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=5e5+1145;const int MAXN=1e5+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NO PATH")
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("Road.in","r",stdin);
//	freopen("Road.out","w",stdout);
//}
int n,rm,sm,s;
struct Edge {
	int u,v,w,nxt;
}edge[MAXM];
int totr,head[MAXN];
inline void add_edge(int u,int v,int w) {
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].w=w;
}
struct node {
	int u,dis;
	bool operator <(node b) const {return dis>b.dis;}
};
std::priority_queue<node>que;
int dis[MAXN];
#define v edge[i].v
#define w edge[i].w
inline void Dijkstra() {
	for(int i=1;i<=n;i++) dis[i]=INF;
	int u=s;dis[u]=0;
	que.push((node){u,dis[u]});
	while(!que.empty()) {
		node p=que.top();que.pop();
		u=p.u;if(dis[u]<p.dis) continue;
		for(int i=head[u];i;i=edge[i].nxt) {
			if(dis[v]>dis[u]+w) dis[v]=dis[u]+w,que.push((node){v,dis[v]});
		}
	}
}
#undef v
#undef w
int main(){
//	_File();
	read(n);read(rm);read(sm);read(s);
	for(int i=1;i<=rm;i++) {
		int u,v,w;
		read(u),read(v),read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=sm;i++) {
		int u,v,w;
		read(u),read(v),read(w);
		add_edge(u,v,w);
	}
	Dijkstra();
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==INF) pn;
		else write(dis[i]),pc;
	}
	return 0;
}


