/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM+1145];
int head[MAXN],totr;
int s;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
EDGE e[MAXM+1145];int head2[MAXN],totr2;
void add_edge2(int u,int v){
	e[++totr2].u=u;
	e[totr2].v=v;
	e[totr2].nxt=head2[u];
	head2[u]=totr2;
}
int low[MAXN],dfn[MAXN],dfs_num,num,scc[MAXN],siz[MAXN],scval[MAXN],val[MAXN];
bool vis[MAXN],in_stack[MAXN];
std::stack<int>sta;
void Tarjan(int u) {
	low[u]=dfn[u]=++dfs_num;in_stack[u]=1;
	vis[u]=true;sta.push(u);
	for(int i=head[u];i;i=edge[i].nxt) {
		#define v edge[i].v
		if(!dfn[v]){
			Tarjan(v);low[u]=min(low[v],low[u]);
		}
		else if(in_stack[v])low[u]=min(low[u],dfn[v]);
		#undef v
	}
	if(dfn[u]==low[u]) {
		++num;
		while(sta.top()!=u) {
			scval[num]+=val[sta.top()];
			scc[sta.top()]=num;
			in_stack[sta.top()]=false;
			siz[num]++;
			sta.pop();
		}
		scval[num]+=val[sta.top()];
		scc[sta.top()]=num;
		in_stack[sta.top()]=false;
		siz[num]++;
		sta.pop();
	}
	
}
int rd[MAXN];
bool vvis[MAXN];
bool p[MAXN];
bool scp[MAXN];
void dfs(int u) {
	vvis[u]=1;
	#define v edge[i].v
	for(int i=head[u];i;i=edge[i].nxt) {
		scp[scc[u]]|=p[u];
		scp[scc[v]]|=p[v];
		if(scc[u]!=scc[v]) add_edge2(scc[u],scc[v]),rd[scc[v]]++;
		if(!vvis[v]) dfs(v);
	}
	#undef v
}
int dis[MAXN];
int topo() {
	memset(in_stack,0,sizeof(in_stack));
	std::stack<int>stac;int ans=0;
	stac.push(s);
	in_stack[s]=1;
	while(!stac.empty()) {
		int u=stac.top();stac.pop();
		dis[u]+=scval[u];in_stack[u]=false;
		if(scp[u]) ans=max(ans,dis[u]);
		for(int j=head2[u];j;j=e[j].nxt) {
			dis[e[j].v]=max(dis[e[j].v],dis[u]);
			rd[e[j].v]--;
			if(!rd[e[j].v]) stac.push(e[j].v);
		}
	}
	return ans;
}

int main() {
	int n,m,u,v;
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		read(u);read(v);
		add_edge(u,v);
	}
	for(int i=1;i<=n;i++) read(val[i]);
	read(s);read(u);
	for(int i=1;i<=u;i++) read(v),p[v]=true;
	Tarjan(s);
	dfs(s);
	s=scc[s];
    write(topo());
}
