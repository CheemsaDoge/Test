/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {
	_x=0;    //fast input
	T _w=1,_ch=getchar();
	while(!isdigit(_ch)&&_ch!='-')_ch=getchar();
	if(_ch=='-')_w=-1,_ch=getchar();
	while(isdigit((int)_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();
	_x=_x*_w;
}
template<typename T> inline void write(T _x) {
	static char _q[65];
	int _cnt=0;
	if(_x<0)putchar('-'),_x=-_x;
	_q[++_cnt]=char(_x%10),_x/=10;
	while(_x)_q[++_cnt]=char(_x%10),_x/=10;
	while(_cnt)putchar(_q[_cnt--]+'0');
}
const int MAXM=2e5+1145;
const int MAXN=4e5+1145;
const int INF=2147483647ll;//2^31-1
const int MAXL=1e6+1145;
#define pc putchar('\n')
#define pk putchar(' ')
#define ll long long int
/*---------------------------------pre------------------------------------*/
int f[MAXN][30],cnt=0;
ll w[MAXN];
bool flag[MAXN];
vector <int> G[MAXN];
struct edge {
	int nxt,v;
} e[MAXN];
int head[MAXN],ecnt=0;
inline void _add(int u,int v) {
	e[++ecnt].v=v,e[ecnt].nxt=head[u],head[u]=ecnt;
}
ll ans=0;
inline void insert(char s[]) {
	int u=0;
	for(int i=(int)strlen(s)-1; i>=0; i--) {
		int t=s[i]-'a';
		if(!f[u][t])f[u][t]=++cnt,G[u].push_back(t);
		u=f[u][t];
	}
	flag[u]=1;
}
inline void rego(int u,int fa) {
	int las=(flag[u]) ? u:fa;
	for(int i=0; i<(int)G[u].size(); i++) {
		int v=f[u][G[u][i]];
		if(flag[v])_add(las,v);
		rego(v,las);
		w[u]+=w[v];
	}
	if(flag[u])w[u]++;
}
struct pi {
	int id;
	ll sum;
} p[MAXN];
int top=0;
bool cmp(pi a,pi b) {
	return a.sum<b.sum;
}
inline void DFS(int u) {
	ll l=top+1;
	for(int i=head[u]; i; i=e[i].nxt) {
		int v=e[i].v;
		p[++top]=(pi){v,w[v]};
	}
	ll r=top;
	ll all=r-l+1;
	if(all>0) {
		sort(p+l,p+r+1,cmp);
		ans+=all;
		for(ll i=l; i<=r; i++) {
			ans+=1ll*(all-(i-l+1))*w[p[i].id];
			DFS(p[i].id);
		}
	}
}
char c[MAXL];
signed main() {
	freopen("word.in","r",stdin);
	freopen("word.out","w",stdout);
	ll n;
	read(n);
	for(int i=1; i<=n; i++) {
		scanf("%s",c);
		insert(c);
	}
	rego(0,0);
	DFS(0);
	write(ans);
}
