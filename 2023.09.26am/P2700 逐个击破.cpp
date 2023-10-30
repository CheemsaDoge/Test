/*code by CheemsaDoge*/
#include <bits/stdc++.h>
namespace CheemsaDoge{
	template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
	template <typename T> inline void write(T _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
	template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
	template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
	template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
	template <typename types,typename ... Args> inline void write(types x, Args ... args) {write(x),putchar(' '),write(args...);}
}
using namespace CheemsaDoge;
const int MAXM=1e6+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
	const bool operator <(Edge b) const {return val>b.val;}
}edge[MAXM];
int head[MAXN],totr=0;
void add_edge(int u,int v,int val=0) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
long long int n,k,tmp,tmpp,sum=0;
bool vis[MAXN];
int fa[MAXN];
inline void initialize() {for(int i=1;i<=n;i++) fa[i]=i;}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y) {vis[find(y)]|=vis[find(x)];fa[find(x)]=find(y);}
int main() {
	read(n,k);
	initialize();
	for(int i=1;i<=k;i++) read(tmp),vis[tmp]=true;
	for(int i=1;i<n;i++) {long long u,v,w;read(u,v,w),add_edge(u,v,w);sum+=w;}
	std::sort(edge+1,edge+n);
	for(int i=1;i<n;i++) {
		int u=find(edge[i].u),v=find(edge[i].v);
		if(!(vis[u]&&vis[v])) merge(u,v),sum-=edge[i].val;
	}
	write(sum);
	return 0;
}

