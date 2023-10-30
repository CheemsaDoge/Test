/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=3e5+1145;const int MAXN=450;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("Begin.in","r",stdin);
//	freopen("Begin.out","w",stdout);
//}
int n;
int p[MAXN][MAXN];
struct Edge{
	int u,v,w,nxt;
	bool operator <(Edge b) const {return w < b.w;}
}edge[MAXM];
int totr,head[MAXN];
inline void add_edge(int u,int v,int w)
{
	edge[++totr].nxt=head[u];
	head[u]=totr;
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].w=w;
}
const int S=305;
int fa[MAXN];
inline void initialize() {for(int i=1;i<=305;i++) fa[i]=i;}
inline int find(int _a) {return fa[_a]==_a?_a:fa[_a]=find(fa[_a]);}
int main(){
//	_File();
	int v,ans=0,cnt=0;read(n);
	for(int i=1;i<=n;i++) read(v),add_edge(i,S,v);
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) read(p[i][j]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) if(p[i][j]) add_edge(i,j,p[i][j]);	
	std::sort(edge+1,edge+1+totr);
	initialize();
	for(int i=1;i<=totr&&cnt<=n-1;i++) {
		#define u edge[i].u
		#define v edge[i].v
		#define w edge[i].w
		if(find(u)!=find(v)) {
			cnt++;
			ans+=w;
			fa[find(u)]=v;
		}
	}
	write(ans);
	return 0;
}


