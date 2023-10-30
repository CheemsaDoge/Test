/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e5;const int MAXN=5000;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
const double eps=1e-10;
/*---------------------------------pre------------------------------------*/
inline void _File(){
	freopen("Circle.in","r",stdin);
	freopen("Circle.out","w",stdout);
}
int n,k,m;
struct Edge{
	int u,v,nxt;
	double w;
}edge[MAXM];
int head[MAXN],totr;
inline void add_edge(int _u,int _v,int _w) {
	edge[++totr].nxt=head[_u];
	head[_u]=totr;
	edge[totr].u=_u;
	edge[totr].v=_v;
	edge[totr].w=(double)_w;
}
bool vis[MAXN];
double dis[MAXN];
inline bool dfs(int u,double mid) {
	vis[u]=true;
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
		double w=edge[i].w-mid;
		if(dis[v]>dis[u]+w) {
			dis[v]=dis[u]+w;
			if(vis[v]||dfs(v,mid)) return true;
		}
	}
	vis[u]=false;
	return false;
}
inline bool check(double mid) {
	for(int i=1;i<=n;i++) dis[i]=0,vis[i]=false;
	for(int i=1;i<=n;i++) if(dfs(i,mid)) return true;
	return false;
}
int main(){
	_File();
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		int u,v,w;
		read(u);read(v);read(w);
		add_edge(u,v,w);
	}
	double R=10000000;double L=-R;
	while(fabs(R-L)>eps) {
		double mid=(L+R)/2.0;
		if(check(mid)) R=mid;
		else L=mid;
	}
	printf("%.8lf",L);
	return 0;
}

