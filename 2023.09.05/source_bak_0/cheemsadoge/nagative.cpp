/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=1e4+1145;const int MAXN=2e4+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
const double eps = 1e-10;
/*---------------------------------pre------------------------------------*/
int n,m;
struct EDGE{
	int v,nxt;
	double w;
}e[MAXM*4];
bool vis[MAXN];
int head[MAXN],totr;
double dis[MAXN];
void add_edge(int _u,int _v,double _w)
{
	e[++totr].v=_v;
	e[totr].w=_w;
	e[totr].nxt=head[_u];
	head[_u]=totr;
}
inline bool SPFA(int u, double mid) { 
	vis[u]=true;
	for (int i=head[u];i;i=e[i].nxt) {
		int v=e[i].v;
		double w=e[i].w-mid;
		if (dis[u]+w<dis[v]) {
			dis[v]=dis[u]+w;
			if(vis[v]||SPFA(v, mid)) return true;
		}
	}
	vis[u]=false;
	return 0;
}

inline bool check(double mid) {
	for(int i=1;i<=n;++i) dis[i]=0,vis[i]=false;
	for(int i=1;i<=n;++i) if(SPFA(i, mid)) return true;
	return false;
}
int IN_u,IN_v;
double IN_w;
int main()
{
	freopen("nagative.in","r",stdin);
	freopen("nagative.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%lf",&IN_u,&IN_v,&IN_w);
		add_edge(IN_u,IN_v,IN_w);
//		add_edge(IN_v,IN_u,IN_w);
	}
	double L=-(1e7+0.0),R=1e7+0.0;
	while (R-L>1e-10) {
		double mid=(L+R)/2.0;
		if (check(mid)) R=mid;
		else L=mid;
	}
	printf("%.8lf\n",L);
	return 0;
}
