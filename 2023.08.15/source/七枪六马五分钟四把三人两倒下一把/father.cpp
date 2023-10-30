/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n');
#define py puts("yes")
#define pn puts("no")
/*---------------------------------pre------------------------------------*/
int n, m, tot, ti, dfn;
int head[MAXN], to[MAXN<<1], nex[MAXN<<1], euler[30][MAXN<<1], dep[MAXN], pos[MAXN];
int lg[MAXN<<1];
// euler[i][j]: 锟斤拷锟斤拷 [j, j + 2^i) 锟斤拷 dep 锟斤拷小锟侥节碉拷锟斤拷

void add_edge(int u, int v) {
	to[++tot] = v;
	nex[tot] = head[u];
	head[u] = tot;
}

void dfs(int u, int fa = 0, int deep = 1) {
	euler[0][++dfn] = u;
	pos[u] = dfn;
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
}

int query(int u, int v) {
	int l = pos[u], r = pos[v];
	if (l > r) swap(l, r);
	int k = lg[r - l + 1];
	return dep[euler[k][l]] < dep[euler[k][r - (1<<k) + 1]] ? euler[k][l] : euler[k][r - (1<<k) + 1];
}
int u,v,k;

int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("father1.in","r",stdin);
//	freopen("father.out","w",stdout);
	read(n);read(m);
	for(int i=1;i<n;i++)
	{
		read(u);read(v);
		add_edge(u,v);add_edge(v,u);
	}
	dfs(1);
	init();
	for (int i=1, u, v; i<=m; ++i) {
		read(u);read(v);
		if(query(u,v)==u) py;
		else pn;
	}
}
