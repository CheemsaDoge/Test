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
	#define vector std::vector
	#define sort std::sort
}
using namespace CheemsaDoge;
const int MAXM=3e5+10;const int MAXN=1e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;bool c;
	const bool operator <(Edge b) const {return val<b.val;}
}edge[MAXM];
int head[MAXN],totr=0;
inline void add_edge(int u,int v,int val=0) {
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m,k;
int tmp;
int cnt=0;
int fa[MAXN];
vector<int>ans;
inline void initialize() {for(int i=1;i<=n;i++) fa[i]=i;}
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void Kruskal() {
	sort(edge+1,edge+totr);
	initialize();
	for(int i=1;i<=totr;i++) {
		int u=edge[i].u,v=edge[i].v;
		if(find(u)!=find(v)) {
			ans.push_back(i);
			cnt++;
			fa[find(u)]=find(v);
			if(edge[i].c) tmp++;
			if(cnt>=n-1) return ;
		}
	}
}
signed main() {
	read(n,m,k);
	srand(114514+(int)time(0)+1919810);
	for(int i=1;i<=m;i++) {
		int a,b,c;
		read(a,b,c);
		add_edge(a,b,rand()%1000086);
		edge[totr].c=c==0?1:0;
	}
	int l=-1000086,r=1000086;//Ï²»¶10086Äó£»
	while(l<=r) {
		int mid=(l+r)>>1;
		for(int i=1;i<=totr;i++) 
			if(edge[i].c) edge[i].val+=mid;
		tmp=0;cnt=0;
		Kruskal();
		if(cnt<n-1) break;
		if(tmp>k) l=mid+1;
		else if(tmp<k) r=mid-1;	
		else {
			for(auto i : ans) write(edge[i].u,edge[i].v,edge[i].c?0:1),pc;
			return 0;
		}
		for(int i=1;i<=totr;i++) 
			if(edge[i].c) edge[i].val-=mid;
		ans.clear();
	}
	puts("no solution");
	return 0;
}
