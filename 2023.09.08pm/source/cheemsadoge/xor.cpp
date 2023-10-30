/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=2e6+1145;const int MAXN=2e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,w,nxt;
}edge[MAXM];
int head[MAXN],totr=-1,dis[MAXN];
void add_edge(int u,int v,int w){
	edge[++totr].nxt=head[u];
	edge[totr].v=v;
	edge[totr].w=w;
	edge[totr].u=u;
	head[u]=totr;
}
#define v edge[i].v
#define w edge[i].w
void dfs(int x,int fa){for(int i=head[x];~i;i=edge[i].nxt){if(v==fa) continue;dis[v]=dis[x]^w;dfs(v,x);}}
#undef v
#undef w
int tot;
int tr[MAXN][2];
void build(int val){
	int x=0;
	for(int i=1<<30;i;i>>=1){
		bool c=bool(val&i);
		x=tr[x][c]?(tr[x][c]):(tr[x][c]=++tot);
	}
}
int query(int val){
	int ans=0;
	int x=0;
	for(int i=(1<<30);i;i>>=1){
		bool c=bool(val&i);
		if(tr[x][!c]) ans+=i,x=tr[x][!c];
		else x=tr[x][c];
	}
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	memset(head,-1,sizeof(head));
	int n,u,v,w;
	read(n);
	for(int i=1;i<n;++i){
		read(u),read(v),read(w);
		add_edge(u,v,w);add_edge(v,u,w);
	}
	dfs(1,-1);
	for(int i=1;i<=n;++i) build(dis[i]);
	int ans=0;
	for(int i=1;i<=n;++i) ans=max(ans,query(dis[i]));
	write(ans);
	return 0;
}
