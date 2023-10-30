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
int low[MAXN],dfn[MAXN],dfs_num,num,scc[MAXN],siz[MAXN];
bool vis[MAXN],in_stack[MAXN];
stack<int>sta;
void Tarjan(int u)
{
	low[u]=dfn[u]=++dfs_num;in_stack[u]=1;
	vis[u]=true;sta.push(u);
	for(int i=head[u];i;i=edge[i].nxt)
	{
		#define v edge[i].v
		if(!vis[v]){
			Tarjan(v);low[u]=min(low[v],low[u]);
		}
		else if(in_stack[v])low[u]=min(low[u],dfn[v]);
		#undef v
	}
	if(dfn[u]==low[u]){
		++num;
		while(sta.top()!=u)
		{
			scc[sta.top()]=num;
			in_stack[sta.top()]=false;
			siz[num]++;
			sta.pop();
		}
		scc[sta.top()]=num;
		in_stack[sta.top()]=false;
		siz[num]++;
		sta.pop();
	}
	
}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
}
