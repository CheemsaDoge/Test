/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=3e5+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,k;
struct EDGE{
	int u,v,val,nxt;
}edge[MAXN*3];
int head[MAXN],totr;
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
}
int IN_u,IN_v;
void Datain()
{
	read(n);read(k);
	for(int i=1;i<n;i++)
	{
		read(IN_u),read(IN_v);
		add_edge(IN_u,IN_v,1);
		add_edge(IN_v,IN_u,1);
	}
}
bool vis[MAXN];
inline int max(const int a,const int b) {return a>b?a:b;}
int maxd,root;
void _dfs(int u,int dep)
{
	#define v edge[i].v
	vis[u]=true;
	if(dep>maxd)
	{
		maxd=dep;
		root=u;
	}
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(vis[v]) continue;
		_dfs(v,dep+1);
	}
	vis[u]=false;
}
int dfs(int u,int dep)
{
	#define v edge[i].v
	vis[u]=true;
	int _tmp,mxd;
	for(int i=head[u];i;i=edge[i].nxt)
	{
		if(vis[v]) continue;
		_tmp=dfs(v,dep+1);
		mxd=_tmp;
		edge[i].val=mxd;
	}
}
int main()
{
	freopen("greedy.in","r",stdin);
	freopen("greedy.out","w",stdout);
	Datain();

	write(0);
	return 0;
}
