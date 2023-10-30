/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=3e5+1145;const int MAXN=1e5+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
#define white 0
#define black 1
[[maybe_unused]]inline void _File(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
}
struct Edge{
	int u,v,w,nxt,col;
}edge[MAXM];
bool cmp(Edge a,Edge b)
{
	return a.w==b.w?a.col<b.col:a.w<b.w;
}
int totr,head[MAXN];
inline void add_edge(int u,int v,int w,int col)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].w=w;
	edge[totr].col=col;
	head[u]=totr;
}
int n,m,need;
int fa[MAXN],siz[MAXN];
inline void ini() {for(int i=0;i<=n;i++) fa[i]=i;}
inline int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
inline void merge(int x,int y) {fa[find(y)]=x;find(y);}
inline int Kruskal()
{
	ini();
	int numw=0;
	int sum=0,cnt=0;
	for(int i=1;i<=totr;i++)
	{
		Edge e=edge[i];
		if(find(e.u)!=find(e.v))
		{
			cnt++;
			merge(e.u,e.v);
			sum+=e.w;
			if(e.col==white) numw++;
			if(numw>need) return 0;
			if(cnt==n-1) return numw==need?sum:-1;
		}
	}
	return 0;
}
inline void cw(int oldv,int newv)
{
	for(int i=1;i<=totr;i++) 
		if(edge[i].col==white)
			edge[i].w+=newv-oldv;
	sort(edge+1,edge+1+totr,cmp);
}
int main(){
//	_File();
	read(n);read(m);read(need);
	for(int i=1;i<=m;i++)
	{
		int u,v,w,col;
		read(u);read(v);read(w);read(col);
		add_edge(u+1,1+v,w,col);
	}
	int last=0;
	int l=-111,r=111,mid,ans;
	while(l<=r)
	{
		mid=(l+r)>>1;
		cw(last,mid);
		ans=Kruskal();
		if(ans>0) {write(ans-need*mid);return 0;}
		else if(ans==0) l=mid+1;
		else r=mid-1;
		last=mid;
	}
	return 0;
}


