/*code by CheemsaDoge*/
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while((!isdigit(_ch)&&_ch!='-')||_ch=='\r'||_ch=='\n')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch)&&_ch!='\n'&&_ch!='\r')_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
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
		freopen("sakuya.in","r",stdin);
		freopen("sakuya.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
using namespace OI_File;
typedef long long LL;
typedef __int128_t int128; 
const int MAXN=1.2e6;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
LL n,m;
LL siz[MAXN],p[MAXN],f[MAXN],dep[MAXN],ans;
bool spe[MAXN];
struct EDGE{
	LL u,v,val,nxt;
}edge[MAXN+114];
int head[MAXN],totr;
void add_edge(int u,int v,int w) {
	edge[++totr].u=u;
	edge[totr].v=v;
	edge[totr].val=w;
	edge[totr].nxt=head[u];
	head[u]=totr;
}
void dfs1(int now,int fath) {
	dep[now]=dep[fath]+1;
	if(spe[now]) p[now]++;
	for(int i=head[now];i;i=edge[i].nxt) {
		int v=edge[i].v;
		if(v==fath) continue;
		dfs1(v,now);
		p[now]+=p[v];
	}
	return void();
}
LL get(int x,int y) {return dep[x]>dep[y]?p[x]*(m-p[x]):p[y]*(m-p[y]);}
void dfs2(int now,int fath) {
	for(int i=head[now];i;i=edge[i].nxt) {
		int v=edge[i].v;
		f[now]=(f[now]+get(now,v))%MOD;
		if(v==fath) continue;
		dfs2(v,now);
		ans=(ans+edge[i].val*get(v,now))%MOD;
	}
}
signed main() {
	_File();
	scanf("%lld%lld",&n,&m);
	LL times=pow(m,MOD-2,MOD)*2%MOD;
	srand(int('I'+'h'+'a'+'t'+'e'+'C'+'C'+'F')+time(NULL));
	for(int i=1;i<n;i++) {
		int u,v,w;scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	for(int i=1;i<=m;i++) {
		int tmp;read(tmp);spe[tmp]=true;
	}
	dfs1(1,1);dfs2(1,1);
	int t;scanf("%d",&t);
	while(t--) {
		int x,k;scanf("%d%d",&x,&k);
		ans+=f[x]*k%MOD;ans%=MOD;
		write(ans*times%MOD,'\n');
	}
	return 0;
}

