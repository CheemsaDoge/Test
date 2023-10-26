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
		freopen("price.in","r",stdin);
		freopen("price.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=1.5e6;
int INF=-1147483647;
/*---------------------------------pre------------------------------------*/
int n,f[MAXN][2],a[MAXN],b[MAXN],p[MAXN];
struct node {int x,y;};
bool operator <(node x,node y) {return x.y<y.y;}
std::priority_queue<node>que;
int main()
{
	_File();read(n);
	for(int i=1;i<=n;i++) read(a[i],b[i]);
	int l=1,r=0,ans=0;
	for(int i=1;i<=n;i++) {
		int maxn=l-1;
		while(!que.empty()&&que.top().y>b[i]) maxn=max(maxn,que.top().x),que.pop();
		r++;l=maxn+1;
		ans=max(ans,r-l+1);
		que.push({i,a[i]});
	}
	write(ans);
	return 0;
}
//int n,ans;
//int l[MAXN],r[MAXN];
//std::multiset<int>st;
//signed main() {
////	_File();
//	read(n);
//	for(int i=1;i<=n;i++) {
//		read(l[i],r[i]);
//		if(l[i]>r[i]) swap(l[i],r[i]);
//	}
//	int now=l[1];
//	int length=1;
//	st.insert(-l[1]);
//	for(int i=2;i<=n;i++) {
//		if(now>r[i]) {
//			ans=max(ans,length);
//			while(now>r[i]&&!st.empty()) {
//				st.erase(st.find(-l[i-length]));
//				length--;
//				now=-*st.lower_bound(INF);
//			}
//			st.insert(-l[i]);
//		}
//		else {
//			now=max(now,l[i]);
//			st.insert(-l[i]);
//		}
//		length++;
//	}
//	write(max(ans,length));
//	return 0;
//}
/*
6
6 10
1 5
4 8
2 5
6 8
3 5
*/