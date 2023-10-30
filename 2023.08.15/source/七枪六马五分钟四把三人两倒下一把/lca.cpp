/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n');
#define pk putchar(' ');
/*---------------------------------pre------------------------------------*/
int n, m, tot, ti, dfn;
int head[MAXN], to[MAXN<<1], nex[MAXN<<1], euler[30][MAXN<<1], dep[MAXN], pos[MAXN];
int lg[MAXN<<1];
int minn[MAXN][30];
int maxn[MAXN][30];
void add_edge(int u, int v) {
	to[++tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
}
void dfs(int u, int fa = 0, int deep = 1) {
	euler[0][++dfn] = u;
	pos[u] = dfn;
	minn[u][0]=dfn;maxn[u][0]=dfn;
	dep[u] = deep;
	for (int i=head[u]; i; i=nex[i]) {
		int v = to[i];
		if (fa == v) continue;
		dfs(v, u, deep + 1);
		euler[0][++dfn] = u;
	}
}

void init() {
	for (int i=2; i<= dfn+1; ++i) lg[i] = lg[i >> 1] + 1;
	for (int i=1; i <= lg[dfn]; ++i) {
		for (int j = 1; j + (1<<i) - 1 <= dfn; ++j) {
			if (dep[euler[i-1][j]] < dep[euler[i-1][j + (1<< i-1)]])
				euler[i][j] = euler[i-1][j];
			else
				euler[i][j] = euler[i-1][j + (1<< i-1)];
		}
	}
	int k=log(n)/log(2)+1;
	for (int i=1; i <= k; ++i) {
		for (int j = 1; j + (1<<i) - 1 <= n; ++j) {
			minn[j][i]=min(minn[j][i-1],minn[j+(1<<(i-1))][i-1]);
			maxn[j][i]=max(maxn[j][i-1],maxn[j+(1<<(i-1))][i-1]);
		}
	}
//	for(int j=1;j<=k;j++)
//	{
//		for(int i=1;i<=n&&i<=n-(1<<j)+1;i++)
//		{
//			minn[i][j]=min(minn[i][j-1],minn[i+(1<<(j-1))][j-1]);
//			maxn[i][j]=max(maxn[i][j-1],maxn[i+(1<<(j-1))][j-1]);
//		}
//	}
}

int __query(int u, int v) {
	int l = u, r = v;
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return dep[euler[k][l]] < dep[euler[k][r - (1<<k) + 1]] ? euler[k][l] : euler[k][r - (1<<k) + 1];
}
int u,v,k;
int query(int l, int r) {
	int k=log(r-l+1)/log(2);
	return __query(min(minn[r-(1<<k)+1][k],minn[l][k]),max(maxn[r-(1<<k)+1][k],maxn[l][k]));
}
int main()
{
	freopen("lca.in","r",stdin);
	freopen("lca.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);
		add_edge(u,v);add_edge(v,u);
	}
	dfs(1);
	init();
	for (int i=1;i<=m;++i) {
		read(u);read(v);
		write(query(u, v));pc;
	}
}
//如果错了就是LTT 标程有问题（暴论） 
