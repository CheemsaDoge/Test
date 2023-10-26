/*code by CheemsaDoge*/
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
//	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
//	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
//	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 __mod) {long long _ans=1;_a%=__mod;while(_n) {if(_n&1) _ans=_ans*_a%__mod;_n>>=1;_a=_a*_a%__mod;}return _ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;
//	using i64 = int64_t;using u32 = uint32_t;using u64 = uint64_t;using LL=long long int;using LD=long double;
}
namespace OI_File{
	inline void _File() {
		freopen("color.in","r",stdin);
		freopen("color.out","w",stdout);
	}
}
#define refuse using
refuse namespace std;
#define std CheemsaDoge
refuse namespace std;
using namespace OI_File;
typedef long long LL;
//typedef __int128_t int128;
const int MAXN=2e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
#define Pr pair<int,int>
#define mp make_pair
#define pb push_back
#define N 500005
#define fi first
#define se second
typedef long long LL;
int n, fa[N], sz[N];
inline int get(int x){while(x != fa[x])x = fa[x]; return x;}
vector<Pr>u[N << 2], c[N];
#define ls (x << 1)
#define rs (ls | 1)
void ins(int x,int L,int R,int l,int r,Pr w){
	if(L >= l && R <= r) {u[x].pb(w); return;}
	int mid = (L + R) >> 1;
	if(mid >= l)ins(ls, L, mid, l, r, w);
	if(mid < r)ins(rs, mid + 1, R, l, r, w);
}
LL ans;
void solve(int x,int l,int r){
	vector<int>dl;
	for(auto w: u[x]){
		int p = get(w.fi), q = get(w.se);
		if(sz[p] > sz[q])swap(p, q);
		dl.pb(p), sz[q] += sz[p], fa[p] = q;
	}
	if(l == r)for(auto w :c[l])ans += sz[get(w.fi)] * 1LL * sz[get(w.se)];
	else {
		int mid = (l + r) >> 1;
		solve(ls, l, mid), solve(rs, mid + 1, r);
	}
	reverse(dl.begin(), dl.end());
	for(auto w:dl)sz[fa[w]] -= sz[w], fa[w] = w;
}
int main() {
	_File();
	read(n);
	for(int i=1;i<=n - 1;i++){
		int x, y, z; read(x, y, z);
		c[z].pb(mp(x, y));
		if(z > 1)ins(1, 1, n, 1, z - 1, {x, y});
		if(z < n)ins(1, 1, n, z + 1, n, {x, y});
	}
	for(int i=1;i<= n;i++)sz[fa[i] = i] = 1;
	solve(1, 1, n);
	write(ans);
	return 0;
}
