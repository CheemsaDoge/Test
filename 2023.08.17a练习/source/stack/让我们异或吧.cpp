/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define MOD 10007
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM*4];
int head[MAXN],totr;
void add_edge(int u,int v,int val){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int n,s;
int dis[MAXN];
void dfs(int u,int fath)
{
	for(int i=head[u];i;i=edge[i].nxt) if(edge[i].v!=fath) dis[edge[i].v]=dis[u]^edge[i].val,dfs(edge[i].v,u);
}


int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	int m,u,v,w;
	read(n);
	for(int i=1;i<n;i++)
	{
		read(u),read(v),read(w);
		add_edge(u,v,w),add_edge(v,u,w);
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		read(u),read(v);
		write(dis[u]^dis[v]);pc;
	}
}

//1 /lt n /le 2 /times 10^5
