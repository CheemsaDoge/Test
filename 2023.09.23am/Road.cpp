/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=1e5+10;const int MAXN=3e4+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr=1;
void add_edge(int u,int v,int val=0) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m;
int dfn[MAXN],low[MAXN],dfs_num;
int ans;
bool vis[MAXN];
void Tarjan(int u,int last=-1) {
	dfn[u]=low[u]=++dfs_num;
	vis[u]=true;
	for(int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
		if((i^1)==last) continue ;
		if(!dfn[v]) Tarjan(v,i),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(dfn[v],low[u]);
		if(low[v]>dfn[u]) ans++;
	}
	vis[u]=false;
}
int tmp1,tmp2;
int main() {
	while(1) {
		read(n);read(m);
		if(n==m&&n==0) return 0;
		for(int i=1;i<=m;i++) {
			read(tmp1);read(tmp2);
			add_edge(tmp1,tmp2);
			add_edge(tmp2,tmp1);
		}
		for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
		write(ans);pc;
		memset(edge,0,sizeof(edge));
		totr=ans=dfs_num=0;totr=1;
		memset(head,0,sizeof(head));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
	}
	return 0;
}
