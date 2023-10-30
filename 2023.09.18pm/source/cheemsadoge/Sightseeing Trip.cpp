/*code by CheemsaDoge*/
#include <bits/stdc++.h>
//using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXN=1e3;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("No solution.")
/*---------------------------------pre------------------------------------*/
//[[maybe_unused]]inline void _File(){
//	freopen("x.in","r",stdin);
//	freopen("x.out","w",stdout);
//}
template<typename T> inline T min(const T a,const T b) {return a>b?b:a;}
int edge[MAXN][MAXN];
int n,m,ans=INF;
std::vector<int>e[MAXN];
std::stack<int>sta;
std::stack<int>sta1;
std::stack<int>sta2;
int minn=INF;
int dis[MAXN];
bool vis[MAXN];
int deep[MAXN];
void dfs(int dep,int fa,int u)
{
	sta.push(u);
	deep[u]=dep;
	vis[u]=true;
	int ddep;
	dis[u]=dis[fa]+edge[fa][u];
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fa) continue;
		if(dis[v]==INF||!vis[v]) dfs(dep+1,u,v);
		else {
			ddep=dep-deep[v]+1;
			int val=dis[u]-dis[v]+edge[u][v];
			if(val<minn)
			{
				while(!sta1.empty()) sta1.pop();
				minn=val;
				for(int j=1;j<=ddep;j++)
				{
					sta1.push(sta.top());
					sta2.push(sta.top());
					sta.pop();
				}
				for(int j=1;j<=ddep;j++)
				{
					sta.push(sta2.top());
					sta2.pop();
				}
			}
		}
	}
	sta.pop();
	vis[u]=false;
}
int main(){
//	_File();
	read(n);read(m);
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) edge[i][j]=INF;
	for(int i=1;i<=m;i++) {
		int u,v,w;
		read(u);read(v);read(w);
		if(edge[u][v]==INF) {
			e[u].push_back(v);
			e[v].push_back(u);
		}
		edge[u][v]=min(edge[u][v],w);
		edge[v][u]=min(edge[v][u],w);
	}
	for(int i=1;i<=n;i++) dis[i]=INF;
	for(int i=1;i<=n;i++) if(dis[i]==INF) dfs(0,0,i);
	while(!sta1.empty())
	{
		write(sta1.top());pk;
		sta1.pop();
	}
	return 0;
}


