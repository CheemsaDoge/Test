/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1510;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,m;
int fa[MAXN];
int dist1[510][510],dist2[510][510];
struct node{
	int a,b,w;
	bool flag;
	bool operator<(const node & x)const {return w<x.w;}
}edge[MAXM];
int head[MAXN],totr;
struct Edge{
	int to,w,nxt;
}e[MAXM*2];
void ini() {for(int i=0;i<=n;i++) fa[i]=i;}
inline int find(int x) {return fa[x]!=x?fa[x]=find(fa[x]):fa[x];} 
void add_edge(int a,int b,int c) {
	e[++totr].to=b;
	e[totr].w=c;
	e[totr].nxt=head[a];
	head[a]=totr;
}
void dfs(int u,int fa,int maxd1,int maxd2,int ti) 
{ 
	dist1[ti][u]=maxd1;dist2[ti][u]=maxd2; 
	for (int i=head[u];i;i=e[i].nxt) {
		int To=e[i].to,W=e[i].w;
		if(To!=fa) {
			int td1=maxd1,td2=maxd2;
			if(W>td1) td2=td1,td1=W;
			else if(W>td2&&W<td1) td2=W;
			dfs(To,u,td1,td2,ti); 
		}
	}
}
int main() 
{
	freopen("milktrans.in","r",stdin);
	freopen("milktrans.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		int a,b,w;
		read(a);read(b);read(w);
		edge[i].a=a;
		edge[i].b=b;
		edge[i].w=w;
//		read(edge[i].a);read(edge[i].b);read(edge[i].w);
		edge[i].flag=0;
	}
	sort(edge+1,edge+1+m);
	ini();
	ll sum=0;
	for(int i=1;i<=m;i++) { //Kruskal
		int a=edge[i].a,b=edge[i].b,w=edge[i].w;
		if(find(a)!=find(b)) {
			fa[find(a)]=find(b);
			sum+=w;
			add_edge(a,b,w);add_edge(b,a,w);
			edge[i].flag=1;
		}
	}
	for(int i=1;i<=n;i++) dfs(i,-1,0,0,i);//get max/sec_max dis from i to v 
	ll res=5e18;
	for(int i=1;i<=m;i++)
		if(edge[i].flag==0)
		{
			int a=edge[i].a,b=edge[i].b,w=edge[i].w;
			ll t;
			if(w>dist1[a][b])  t=sum+w-dist1[a][b];
			else if(w>dist2[a][b]) t=sum+w-dist2[a][b];
			res=min(res,t);
		}
	write(res);
	return 0;
}

