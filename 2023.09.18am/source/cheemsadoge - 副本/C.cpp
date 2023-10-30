/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
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

int bb;
int main() 
{
	read(n);read(m);
	for(int i=1;i<=m;i++) {
		read(edge[i].a);read(edge[i].b);read(edge[i].w);read(bb);
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
		}
	}
	write(sum);
}
