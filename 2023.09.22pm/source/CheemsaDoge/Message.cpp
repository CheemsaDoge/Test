/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e6+1145;const int MAXN=2e3+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
inline void add_edge(int u,int v,int val) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n;
int low[MAXN],dfn[MAXN],dfs_num;
int vis[MAXN];
int num,scc[MAXN];
std::stack<int>sta;
void Tarjan(int u) {
	low[u]=dfn[u]=++dfs_num;
	vis[u]=true;sta.push(u);
	for(int i=head[u];i;i=edge[i].nxt)
		#define v edge[i].v
		if(dfn[v]==0) Tarjan(v),low[u]=min(low[v],low[u]);
		else if(vis[v]!=0) low[u]=min(low[u],dfn[v]);
		#undef v
	if(dfn[u]==low[u]) {
		++num;
		while(sta.top()!=u) {
			scc[sta.top()]=num;
			vis[sta.top()]=false;
			sta.pop();
		}
		scc[sta.top()]=num;
		vis[sta.top()]=false;
		sta.pop();
	}
}
int rd[MAXN];
int tmp;
int main()
{
//	freopen("news5.in","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			read(tmp);
			if(tmp==1) add_edge(i,j,0);
		}
	for(int i=1;i<=n;i++) 
		if(dfn[i]==0) Tarjan(i);
	for(int i=1;i<=totr;i++) if(scc[edge[i].u]!=scc[edge[i].v]) rd[scc[edge[i].v]]++;
	int ans=0;
	for(int i=1;i<=num;i++) if(rd[i]==0) ans++;
	write(ans);
	return 0;
}

