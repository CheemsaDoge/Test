#include <bits/stdc++.h>
using namespace std;
const int MAXSIZE = 10000020;
namespace CheemsaDoge{
	template <typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &in) {in=getchar();while(in==' '||in=='\n') in=getchar();}
	template <typename T> inline void write(T _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename T> inline T min(const T _a,const T _b) {return _a>_b?_b:_a;}
	template <typename T> inline T max(const T _a,const T _b) {return _a>_b?_a:_b;}
	template <typename T> inline T abs(const T _a) {return _a<0?-_a:_a;}
	template <typename T> inline void swap(T &_x,T &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &x, Args &... args) {read(x), read(args...);}
	template <typename types,typename ... Args> inline void write(types x, Args ... args) {write(x),putchar(' '),write(args...);}
	#define vector std::vector
	#define sort std::sort
}
using namespace CheemsaDoge;
struct edge {
    int to, next;
};
const int maxn = 100001;
const int maxm = 200001;
typedef long long ll;
struct bit {
    int n;
    ll a[maxn];
    void add(int p, ll x) {
        for (; p <= n; p += p & -p) a[p] += x;
    }
    ll query(int p) {
        ll ans = 0;
        for (; p; p -= p & -p) ans += a[p];
        return ans;
    }
} b1, b2;
struct graph {
    int n, m;
    int first[maxn];
    edge e[maxm];
    void addedge(int from, int to) {
        e[++m]=(edge) {to, first[from]};
        first[from] = m;
    }
    int st[maxn], en[maxn], dep[maxn], cl;
    void dfs(int u) {
        st[u] = ++cl;
        for (int i = first[u]; i; i = e[i].next) {
            int v = e[i].to;
            if (st[v])
                continue;
            dep[v] = dep[u] + 1;
            dfs(v);
        }
        en[u] = cl;
    }
    void prepare() {
        dfs(1);
        b1.n = b2.n = n;
    }
    void addv(int u, int x) {
        b1.add(st[u], x);
        b1.add(en[u] + 1, -x);
    }
    void adds(int u, int x) {
        b1.add(st[u], (ll)(1 - dep[u])*x);
        b1.add(en[u] + 1, (ll)(dep[u] - 1)*x);
        b2.add(st[u], x);
        b2.add(en[u] + 1, -x);
    }
    ll query(int u) {
        return b1.query(st[u]) + b2.query(st[u]) * dep[u];
    }
} g;
int a[maxn];
int main() {
	int n,m;read(n,m);g.n=n;
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i < n; i++) {
        int u,v;read(u,v);
        g.addedge(u, v);g.addedge(v, u);
    }
    g.prepare();
    for (int i = 1; i <= n; i++) g.addv(i, a[i]);
    while (m--) {
        int op,tmp;read(op);
        if (op == 3) read(tmp),write(g.query(tmp),'\n');
        else {
            int x,v;read(x,v);
            if (op == 1) g.addv(x, v);
            else g.adds(x, v);
        }
    }
}
