/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template<typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template<typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e6+114514;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
void _File() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
}
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
int n;
bool vis[MAXN];
long long int ans;
int dfs(int u,int fa) {
	int mm=0;
	int siz=0;
	int ms=0;
	for(int i=head[u];i;i=edge[i].nxt) {
		if(edge[i].v!=fa) {
			siz=dfs(edge[i].v,u);
			if(siz>ms) mm+=ms,ms=siz;
			else mm+=siz;
		}
	}
	ans+=1ll*mm*ms;
	return 1+mm+ms;
}

int main()
{
	_File();
	read(n);
	for(int i=1;i<=n-1;i++) {
		int u,v;
		read(u);read(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	write(ans);
	return 0;
}


