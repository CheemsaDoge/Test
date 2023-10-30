/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=2e4+1145;const int MAXN=4e3+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("NO")
#define py puts("YES")
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m,p;
int waste[MAXN];
int low[MAXN],dfn[MAXN],dfs_num;
bool vis[MAXN];
int num,scc[MAXN];
int sccval[MAXN];
std::stack<int>sta;
void Tarjan(int u)
{
	low[u]=dfn[u]=++dfs_num;
	vis[u]=true;sta.push(u);
	for(int i=head[u];i;i=edge[i].nxt)
		#define v edge[i].v
		if(!dfn[v]) Tarjan(v),low[u]=min(low[v],low[u]);
		else if(vis[v]) low[u]=min(low[u],dfn[v]);
		#undef v
	if(dfn[u]==low[u]) {
		++num;
		scc[u]=num;
		sccval[num]=waste[u];
		vis[u]=false;
		while(sta.top()^u) {
			scc[sta.top()]=num;
			sccval[num]=min(sccval[num],waste[sta.top()]);
			vis[sta.top()]=false;
			sta.pop();
		}
		sta.pop();
	}
	
}
int rd[MAXN],ans;
int main()
{
	read(n);read(p);
	for(int i=1;i<=n;i++) waste[i]=INF;
	for(int i=1;i<=p;i++) {
		int x;
		read(x);
		read(waste[x]);
	}
	read(m);
	for(int i=1;i<=m;i++) {
		int u,v;
		read(u);read(v);
		add_edge(u,v,0);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]&&waste[i]!=INF) Tarjan(i);
	for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) {
			pn;
	    	write(i);
            exit(0);
        }
    }
    for (int i=1;i<=totr;i++) 
        if (scc[edge[i].u]^scc[edge[i].v])
            ++rd[scc[edge[i].v]];
    for (int i=1;i<=num;++i) 
        if (!rd[i]) ans+=sccval[i];
    py;
    write(ans);
	return 0;
}

/*
8
7
6 77
1 150
5 113
8 20
7 86
3 127
4 178
10
4 5
8 2
3 7
1 5
2 6
4 3
3 1
4 5
1 5
2 7

YES
198
*/
