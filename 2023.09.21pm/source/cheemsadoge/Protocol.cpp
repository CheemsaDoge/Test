/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e5+1145;const int MAXN=2000;const long long int INF=576460752303423488ll;//2^59
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
inline void _File(){
	freopen("Protocol.in","r",stdin);
	freopen("Protocol.out","w",stdout);
}
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
int n,m;
int dfn[MAXN],low[MAXN],top,vis[MAXN],stk[MAXN];
int tc,cnt;
int belong[MAXN];
void Tarjan(int u) {
	dfn[u]=low[u] = ++tc;
	vis[u]=1;
	stk[++top]=u;
	for (int i=head[u];i;i=edge[i].nxt) {
		int v=edge[i].v;
		if (vis[v]==2) continue;
		if (!vis[v]) Tarjan(v);
		low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u]) {
		cnt++;int v=0;
		while(v^u) {
			v=stk[top--];
			belong[v]=cnt;
			vis[v]=2;
		}
	}
}
int in[MAXN],out[MAXN];
int main()
{
	_File();
	read(n);
	for(int i=1;i<=n;i++) {
		int tmp;
		while(1) {
			read(tmp);
			if(tmp==0) break;
			add_edge(i,tmp,0);
		}
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
	for (int i=1;i<=totr;i++) {
		if (belong[edge[i].u]==belong[edge[i].v]) continue;
		in[belong[edge[i].v]]++;
		out[belong[edge[i].u]]++;
	}
	int s1=0,s2=0;
	for (int i = 1; i <= cnt; i++) {
		if (!in[i]) s1++;
		if (!out[i]) s2++;
	}
	if(cnt==1) write(s1),pc,write(0);
	else write(s1),pc,write(max(s1,s2));
	return 0;
}


