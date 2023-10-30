/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;    //fast input
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
template<typename T> inline void write(T x) {
	static char q[65];
	int cnt=0;
	if(x<0)putchar('-'),x=-x;
	q[++cnt]=x%10,x/=10;
	while(x)q[++cnt]=x%10,x/=10;
	while(cnt)putchar(q[cnt--]+'0');
}
const int MAXM=3e5+1145;
const int MAXN=1e5+1145;
const int INF=2147483647ll;//2^31-1
const long long INF64 = 0x3fffffffffffffffLL;
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge {
	int u, v, val;
	bool operator<(const Edge &other) const {return val<other.val;}
};
Edge e[300210];
bool used[300210];
int n,m;
long long sum;
class Tr {
	private:
		struct Edge {
			int to, nxt, val;
		}e[MAXM*2];
		int cnt, head[MAXN];
		int pnt[MAXN][22];
		int dpth[MAXN];
		int maxx[MAXN][22];
		int minn[MAXN][22];
	public:
		void addedge(int u, int v, int val) {
			e[++cnt] = (Edge) {v, head[u], val};
			head[u] = cnt;
		}
		void insedge(int u, int v, int val) {
			addedge(u, v, val);
			addedge(v, u, val);
		}
		void dfs(int now, int fa) {
			dpth[now] = dpth[fa] + 1;
			pnt[now][0] = fa;
			minn[now][0] = -INF;
			for (int i = 1; (1 << i) <= dpth[now]; i++) {
				pnt[now][i] = pnt[pnt[now][i - 1]][i - 1];
				int kk[4] = {maxx[now][i - 1], maxx[pnt[now][i - 1]][i - 1],
				             minn[now][i - 1], minn[pnt[now][i - 1]][i - 1]
				            };
				std::sort(kk, kk + 4);
				maxx[now][i] = kk[3];
				int ptr = 2;
				while (ptr >= 0 && kk[ptr] == kk[3]) ptr--;
				minn[now][i] = (ptr == -1 ? -INF : kk[ptr]);
			}

			for (int i = head[now]; i; i = e[i].nxt) {
				if (e[i].to != fa) {
					maxx[e[i].to][0] = e[i].val;
					dfs(e[i].to, now);
				}
			}
		}
		int lca(int a, int b) {
			if (dpth[a] < dpth[b]) std::swap(a, b);

			for (int i = 21; i >= 0; i--)
				if (dpth[pnt[a][i]] >= dpth[b]) a = pnt[a][i];

			if (a == b) return a;

			for (int i = 21; i >= 0; i--) {
				if (pnt[a][i] != pnt[b][i]) {
					a = pnt[a][i];
					b = pnt[b][i];
				}
			}
			return pnt[a][0];
		}

		int query(int a, int b, int val) {
			int res = -INF;
			for (int i = 21; i >= 0; i--) {
				if (dpth[pnt[a][i]] >= dpth[b]) {
					if (val != maxx[a][i])
						res = std::max(res, maxx[a][i]);
					else
						res = std::max(res, minn[a][i]);
					a = pnt[a][i];
				}
			}
			return res;
		}
} tr;
int fa[MAXN];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
void Kruskal() {
	int tot = 0;
	sort(e + 1, e + m + 1);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++) {
		int a=find(e[i].u);
		int b=find(e[i].v);
		if (a != b) {
			fa[a] = b;tot++;
			tr.insedge(e[i].u, e[i].v, e[i].val);
			sum += e[i].val;
			used[i] = 1;
		}
		if (tot==n-1) break;
	}
}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int u,v,w;
	read(n);
	read(m);
	for (int i = 1; i <= m; i++) {
		read(u);read(v);read(w);
		e[i]=(Edge) {u,v,w};
	}
	Kruskal();
	long long ans=INF64;
	tr.dfs(1,0);
	for (int i = 1; i <= m; i++) {
		if (!used[i]) {
			int _lca=tr.lca(e[i].u, e[i].v);
			long long tmpa=tr.query(e[i].u, _lca, e[i].val);
			long long tmpb=tr.query(e[i].v, _lca, e[i].val);
			if (max(tmpa, tmpb)>-INF) ans=min(ans,sum-max(tmpa, tmpb)+e[i].val);
		}
	}
	write(ans==INF64?-1:ans);
	return 0;

}

//1 /lt n /le 2 /times 10^5
