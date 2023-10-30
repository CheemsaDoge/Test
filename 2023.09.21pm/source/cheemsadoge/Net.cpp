/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=2e2+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
void add_edge(int u,int v,int val) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m,p,sum;
int low[MAXN],dfn[MAXN],dfs_num;
bool cut[MAXN];
void Tarjan(int u) {
	low[u]=dfn[u]=++dfs_num;
	int flag=0;
	for(int i=head[u];i;i=edge[i].nxt)
		#define v edge[i].v
		if(!dfn[v]) {
			Tarjan(v);low[u]=min(low[v],low[u]);
			if(low[v]>=dfn[u]) {
				flag++;
				if((u!=1||flag>1)&&cut[u]==false) cut[u]=true,sum++;
			}
		}
		else low[u]=min(low[u],dfn[v]);
		#undef v
}
int main()
{
	while(~std::scanf("%d",&n)&&n)
	{
		memset(cut,0,sizeof(cut));
		memset(low,0,sizeof(low));
		memset(dfn,0,sizeof(dfn));
		memset(edge,0,sizeof(edge));
		memset(head,0,sizeof(head));
		totr=0;dfs_num=0;sum=0;
		int u,v;
		while (~scanf("%d",&u)&&u) {
			while (getchar()!='\n') {
				scanf("%d", &v);
				add_edge(u,v,0);
				add_edge(v,u,0);
			}
		}
		Tarjan(1);
		write(sum);pc;
	}
	return 0;
}


