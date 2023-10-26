/*code by CheemsaDoge*/
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-finline")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-fno-stack-protector")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("abm")
#pragma GCC target("avx")
#pragma GCC target("mmx")
#pragma GCC target("popcnt")
#pragma GCC target("sse")
#pragma GCC target("sse2")
#pragma GCC target("sse3")
#pragma GCC target("sse4")
#pragma GCC target("ssse3")
#pragma GCC target("tune=native")
namespace CheemsaDoge {
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
	template <typename type1> inline void write(type1 _x) {static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
	template <> inline void write <char> (char _x) {putchar(_x);}
	template <> inline void write <char*> (char *_x) {int siz=(int)strlen(_x);for(int i=0;i<siz;i++) write(_x[i]);}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename types,typename ... Args> inline void read(types &_x, Args &... args) {read(_x), read(args...);}
	template <typename types,typename ... Args> inline void write(types _x, Args ... args) {write(_x),putchar(' '),write(args...);}
	template <typename type1,typename type2,typename type3> long long pow(type1 _a,type2 _n,type3 _mod) {long long ans=1;_a%=_mod;while(_n) {if(_n&1) ans=ans*_a%_mod;_n>>=1;_a=_a*_a%_mod;}return ans;}
	using std::sort;
	using std::set;
	using std::vector;
	using std::pair;
}
namespace OI_File{
	inline void _File() {
		freopen("x.in","r",stdin);
		freopen("x.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;const LL MOD=1e9+7;
/*---------------------------------pre------------------------------------*/
int t;
int a[60];
LL f[5][5][30][60][30];
int tot;
LL dfs(bool lead,bool limit,int last,int pos,int sum,LL num) {
	if(!pos&&last&&sum&&lead) return (num%MOD)*(num%MOD)%MOD;
	if(!pos) return 0;
	if(!limit&&lead&&f[limit][lead][last][pos][sum]) return f[limit][lead][last][pos][sum];
	int up=limit?a[pos]:9;
	LL res=0;
	for(int i=0;i<=up;i++) {
		if(i==7) continue;
		res=(res+dfs(lead||i,limit&&(i==up),(last*10+i)%7,pos-1,(sum+i)%7,(num*10+i)%MOD))%MOD;
	}
	if(!limit&&lead) f[limit][lead][last][pos][sum]=res;
	return res;
}
inline int calc(LL _x) {
	memset(a,0,sizeof(a));
	int totr=0;
	while(_x) {
		a[++totr]=_x%10;
		_x/=10;
	}
	return totr;
}
LL solve(LL x) {
	int totr=calc(x);
	LL ans=0;//x
	memset(f,0,sizeof(f));
	if(totr<=1) {
		for(int i=1;i<=x;i++) if(i!=7) ans+=i*i;
		return ans;
	}
	int up=a[totr];
	for(int i=0;i<=up;i++) ans=(ans+dfs(!i,up==i,i%7,totr-1,i%7,i))%MOD;
	return (ans+MOD)%MOD;
}

signed main() {
//	_File();
	read(t);
	while(t--) {
		int x,y;
		read(x,y);
		write((solve(y)%MOD-solve(x-1)%MOD+MOD)%MOD,'\n');
	}
	return 0;
}

