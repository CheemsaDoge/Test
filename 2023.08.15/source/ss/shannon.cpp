/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define py puts("yes")
#define pn puts("no")
/*---------------------------------pre------------------------------------*/
struct EDGE{
	int u,v,val,nxt;
	bool tr;
}edge[MAXM*4];
int head[MAXN],totr;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
//int fa[MAXN];
//int find(int x) {return x==fa[x]?x:fa[x]=find(fa[x]);}
//void merge(int x,int y) {fa[find(y)]=find(x);find(y);}
//int cnt;
int n,m,s,t,u,v;
//void Initalize() {for(int i=1;i<=n;i++) fa[i]=i;}
bool once[MAXN];
bool vis[MAXN];
queue<int>qq;
bool dfs(int u)
{
	for(int i=head[u];i;)
	{
		head[u]=edge[i].nxt;
		int v=edge[i].v;
		if(vis[v]) {i=edge[i].nxt;continue;}
		if(once[v])
		{
			if(v==s) return true;
			vis[v]=true;
			for(int j=head[v];j;j=edge[j].nxt) 
				if(edge[j].v!=u&&!vis[edge[j].v]) add_edge(u,edge[j].v);
			i=head[u];continue;
		} 
		once[v]=true;
		i=edge[i].nxt;
	}
	return false;
}

int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("shannon.in","r",stdin);
	freopen("shannon.out","w",stdout);
	read(n);read(m);read(s);read(t);
	for(int i=1;i<=m;i++)
	{
		read(u);read(v);
		if(u!=v) add_edge(u,v),add_edge(v,u);
	}
	vis[t]=1;
	if(dfs(t)) py;
	else pn;
}
