/*code by CheemsaDoge*/
#include<bits/stdc++.h>
namespace CheemsaDoge {
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
	template <typename type1> inline type1 __gcd(type1 _a,type1 _b) {if(!_a||!_b) return _a==0?_b:_a;type1 az=__builtin_ctz(_a),bz=__builtin_ctz(_b);type1 z=min(az,bz),dif;_b>>=bz;while(_a) {_a>>=az;dif=_b-_a;az=__builtin_ctz(dif);if(_a<_b) _b=_a;_a=dif<0?-dif:dif;}return _b<<z;}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	using std::sort;using std::set;using std::vector;using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("enlgcd.in","r",stdin);
		freopen("enlgcd.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e6;const int MAXV=2e7+144;
/*---------------------------------pre------------------------------------*/
int prime[MAXN],v[MAXV],top;
inline void Euler(int n) {
	for(int i=2;i<=n;i++) {
		if(!v[i]) prime[++top]=i,v[i]=i;
		for(int j=1;j<=top;j++) {
			if(prime[j]>v[i]||prime[j]*i>n) break;
			v[i*prime[j]]=prime[j];
		}
	}
	return void();
}
int a[MAXN];
int gcd,maxx,ans;
//std::unordered_map<int,int>hash;
int hash[MAXV];
signed main() {
	_File();int n;read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) {
		gcd=__gcd(gcd,a[i]);
		if(gcd==1) break;
	}
	for(int i=1;i<=n;i++) a[i]/=gcd,maxx=max(maxx,a[i]);
	Euler(maxx);
	for(int i=1;i<=n;i++) {
		if(a[i]==1) continue;
		for(int j=1;j<=top;j++) {
			if(prime[j]>a[i]) break;
			if(!(a[i]%prime[j])) hash[prime[j]]++;
			while(!(a[i]%prime[j])) a[i]/=prime[j];
		}
	}
	for(int i=1;i<=top;i++) ans=max(ans,hash[prime[i]]);
	if(ans==0) return puts("-1"),0;
	return write(n-ans),0;
}
/*
3
7 10000007 15000000
*/
