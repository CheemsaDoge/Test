/*code by CheemsaDoge*/
#include<bits/stdc++.h>
namespace speedup{
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
}
using namespace speedup;
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
	typedef long long LL;
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
const int MAXN=500;
/*---------------------------------pre------------------------------------*/
int n;
int val[MAXN];
int dp[MAXN][MAXN],pre[MAXN][MAXN];
int max_dep;
std::priority_queue<int>que[MAXN];
void dfs(int l,int r,int dep) {
	max_dep=max(max_dep,dep);
	if(l==r) return void();
	int p=pre[l][r];
	que[dep].push(-p);
	dfs(l,p,dep+1);
	dfs(p+1,r,dep+1);
}
signed main() {
//	_File();
	read(n);
	for(int i=1;i<=n;i++) read(val[i]);
	for(int len=1;len<=n;len++) {
		for(int i=1;i+len-1<=n;i++) {
			int p=0;
			for(int j=i;j<len+i-1;j++) {
				int nw=dp[i][j]+dp[j+1][i+len-1]+(val[i]+val[i+len-1])*val[j];
				if(nw>dp[i][i+len-1]) {
					dp[i][i+len-1]=nw;
					p=j;
				}
			}
			pre[i][i+len-1]=p;
		}
	}
	write(dp[1][n],'\n');
	dfs(1,n,1);
	for(int i=1;i<=max_dep;i++) {
		while(!que[i].empty()) write(-que[i].top()),que[i].pop(),putchar(' ');
	} 
	return 0;
}

