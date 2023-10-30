/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=1e5+310;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int d[MAXN],ans,num[MAXN],res;bool vis[MAXN];
struct EDGE{
	int u,v,val,nxt;
}edge[MAXN*3];
int head[MAXN],totr;
void add_edge(int u,int v,int val){
	edge[++totr].u=u;
	edge[totr].val=val;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
void dp(int x)
{
	#define v edge[i].v
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].nxt){
		if(vis[v]) continue;
		dp(v);
		if(d[x]<d[v]+edge[i].val) num[x]=num[v]+1;
		if(ans<d[x]+d[v]+edge[i].val) res=num[v]+1;
		ans=max(ans,d[x]+d[v]+edge[i].val);
		d[x]=max(d[x],d[v]+edge[i].val);
	}
	#undef v
}
int main() {
	freopen("longest.in","r",stdin);
	freopen("longest.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int n,u,v,w;
	read(n);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);read(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	dp(1);
	write(ans);
}
//6
//3  1 1000
//1  4 10
//4  2 100
//4  5 50
//4  6 100

//1110 
//2
//
//
