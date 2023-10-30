/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=2e6+1145;const int MAXN=3e5+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("x.in","r",stdin);
//	freopen("x.out","w",stdout);
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
int minn[MAXN];
struct DisforDj {
//	private:
//	public:
	int u,minn;
	bool operator <(const DisforDj a) const {
		return minn>a.minn;
	}
};
int value[MAXN];
bool cjb[MAXN],vis[MAXN];
int n,m;
int ans=0;
priority_queue<DisforDj>que;
inline bool dfs(int u,int fa) {
	vis[u]=true;
	if(u==n) return cjb[n]=true;
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
		if(!vis[v]&&v!=fa) cjb[u]|=dfs(v,u);
		if(vis[v]&&v!=fa) cjb[u]|=cjb[v];
	}
	return cjb[u];
}
inline int min(const int a,const int b) {return a>b?b:a;}
inline void Dijkstra() {
	memset(vis,0,n+2);
	for(int i=1;i<=n;i++) minn[i]=value[i];
	minn[1]=value[1];vis[1]=1;
	int u=1;DisforDj t;
	que.push((DisforDj){u,minn[u]});
	while(!que.empty()){
		t=que.top();que.pop();
		u=t.u;
		ans=max(value[u]-minn[u],ans);	
		if(t.minn>minn[u]) continue;
		for(int i=head[u];i;i=edge[i].nxt)
		{
			int v=edge[i].v;
			if(!cjb[v]) continue;
			if(minn[v]>minn[u]||!vis[v])
			{
				minn[v]=min(minn[u],minn[v]);
				que.push((DisforDj){v,minn[v]});
				ans=max(value[v]-minn[v],ans);
				vis[v]=1;
			}
		}
	}
}
int main(){
//	_File();
	read(n);read(m);
	for(int i=1;i<=n;i++) read(value[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,op;
		read(u);read(v);read(op);
		add_edge(u,v,1);
		if(op==2) add_edge(v,u,1);
	}
	dfs(1,-1);
	Dijkstra();
//	for(int i=1;i<=n;i++)
//		write(minn[i]),pk;
	write(ans);
	return 0;
}


