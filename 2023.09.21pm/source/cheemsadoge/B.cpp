/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=8e5+10;const int MAXN=2e5+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define ri register int
#define rl register long long
#define ul unsigned long long
#define pn puts("No solution")
/*---------------------------------pre------------------------------------*/
int n,m;
struct Edge{
	int u,v,nxt;
}edge[MAXM];
int head[MAXN],totr=1;
void add_edge(int u,int v){
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
int tot=0;
int dfn[MAXN],dfs_num=0,low[MAXN];
priority_queue<int>st;
int cen1,cen2;
bool cen[MAXN];
bool in_stack[MAXN];
bool check(int u) {
	if(dfn[u]>dfn[cen1]&&dfn[u]<=dfn[cen2]) return true;
	if(dfn[u]<=dfn[cen1]&&dfn[u]>dfn[cen2]) return true;
	return false;
}
void dfs(int u,int from)
{
	#define v edge[i].v
	int child=0;
	low[u]=dfn[u]=++dfs_num;
	for(int i=head[u];i;i=edge[i].nxt) {
		if((i^1)==from)	continue;
		if(!dfn[v])	{
			child++,dfs(v,i),low[u]=min(low[u],low[v]);
			if(low[v]>=dfn[u]&&!in_stack[u]&&check(u))	st.push(-u),in_stack[u]=true;
		}
		else low[u]=min(dfn[v],low[u]);
	}
	#undef v
}

int main()
{
		freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	ri x,y;
	read(n);
	while(1) {
		read(x);read(y);
		if(!x&&!y) break;
		add_edge(x,y);add_edge(y,x);
	}
	read(cen1);read(cen2);
	dfs(1,0);
	if(!st.empty()) write(-st.top());
	else pn;
	return 0;
}

