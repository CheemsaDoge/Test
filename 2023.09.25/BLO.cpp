/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template <typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
const int MAXM=1e6+10;const int MAXN=2e5+10;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,nxt;
}edge[MAXM];
int head[MAXN],totr;
void add_edge(int u,int v) {
	edge[++totr].v=v; 
	edge[totr].nxt=head[u];
	edge[totr].u=u;
	head[u]=totr;
}
long long int dfn[MAXN],low[MAXN],vis[MAXN],ans[MAXN],siz[MAXN];
int n,m,dfs_num;
void Trajan(int u,int fa) {
	long long int size=0;
	dfn[u]=low[u]=++dfs_num;vis[u]=siz[u]=1;
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
		if(v==fa) continue;
		if(!dfn[v]) {
			Trajan(v,u);
			siz[u]+=siz[v];
			low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]) {
				ans[u]+=size*siz[v];
				size+=siz[v];
			}
		}
		else if(vis[v]==1) low[u]=min(low[u],dfn[v]);
	}
	vis[u]=-1;ans[u]+=1ll*size*(n-size-1);
}
int main() {
	read(n);read(m);
	for(int j=0;j<m;j++) {
		int u,v;read(u);read(v);
		add_edge(u,v); add_edge(v,u);
	}
	for(int j=1;j<=n;j++) if(!vis[j]) Trajan(j,-1);
	for(int j=1;j<=n;j++) write(2ll*(ans[j]+n-1)),pc;
	return 0;
}
