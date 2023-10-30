/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
//template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
//template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
	const bool operator <(Edge b) const {
		return val<b.val;
	}
}edge[MAXM];
int head[MAXN],totr=1;
inline void add_edge(int u,int v,int val) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int fa[MAXN];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
int n,m,a;
int cnt;
int main() {
	read(a);read(n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) {
			int tmp;read(tmp);
			if(j<i) continue;
			if(tmp!=0) add_edge(i,j,tmp);
		}
	int ans=0;
	for(int i=1;i<=n;i++) fa[i]=i,add_edge(0,i,a);
	sort(edge+1,edge+1+totr);
	for(int i=1;i<=totr;i++) {
		if(find(edge[i].u)!=find(edge[i].v)) {
			cnt++;
			fa[find(edge[i].u)]=find(edge[i].v);
			ans+=edge[i].val;
			if(cnt==n) break;
		}
	}
	write(ans);
}



