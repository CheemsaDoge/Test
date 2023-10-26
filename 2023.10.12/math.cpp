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
	template <typename type1> inline type1 abs(const type1 _a) {return _a<0?-_a:_a;}
	template <typename type1> inline void swap(type1 &_x,type1 &_y) {_x+=_y;_y=_x-_y;_x-=_y;}
	template <typename type1> inline type1 min(const type1 _a,const type1 _b) {return _a>_b?_b:_a;}
	template <typename type1> inline type1 max(const type1 _a,const type1 _b) {return _a>_b?_a:_b;}
	inline void sread(char *_in) {int _ch=getchar(),top=0;while(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t') _ch=getchar();while(!(_ch==' '||_ch=='\r'||_ch=='\n'||_ch=='\t')) _in[++top]=_ch,_ch=getchar();_in[++top]=0;}
	template <typename type1> inline void read(type1 &_x) {_x=0;type1 _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
	template <> inline void read <char>(char &_in) {_in=(char)getchar();while(_in==' '||_in=='\n') _in=(char)getchar();}
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
		freopen("math.in","r",stdin);
		freopen("math.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef unsigned long long int LL;
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
template <typename type1,typename type2> long long powl(type1 _a,type2 _n) 
{long long ans=1;while(_n) {if(_n&1) ans=ans*_a;_n>>=1;_a=_a*_a;}return ans;}
LL n,m;
LL tenth[50];
namespace MATRIX {
	const int MAXH=114/*514*/,MAXL=191;
	LL MOD=100;
	struct Matrix{
		int h,l;
		LL val[MAXH][MAXL];
		inline void ini() {for(int i=1;i<=h;i++) for(int j=1;j<=l;j++) val[i][j]=0;for(int i=1;i<=h;i++) val[i][i]=1;}
		inline void print() {for(int i=1;i<=h;i++) {for(int j=1;j<=l;j++) write(val[i][j]),putchar(' ');write('\n');}}
		inline void clear() {for(int i=1;i<=h;i++) for(int j=1;j<=l;j++) val[i][j]=0;}
	};
	Matrix operator *(const Matrix &a,const Matrix &b) {
		int nh=a.h;int nl=b.l;
		Matrix c;c.h=nh;c.l=nl;
		for(int i=1;i<=nh;i++) {
			for(int j=1;j<=nl;j++) {
				c.val[i][j]=0;
				for(int k=1;k<=a.l;k++) c.val[i][j]+=LL(a.val[i][k]*b.val[k][j])%MOD,c.val[i][j]=LL(c.val[i][j]+MOD)%MOD;
			}
		}
		return c;
	}
	Matrix pow(Matrix _a,LL _n) {
		if(!_n) return _a;
		Matrix ans;
		ans.h=_a.h;ans.l=_a.l;
		ans.ini();
		while(_n) {
			if(_n&1) ans=ans*_a;
			_n>>=1;
			_a=_a*_a;
		}	
		return ans;
	}
} 
using namespace MATRIX;
signed main() {
	_File();
	read(n,m);
	MOD=m;
	tenth[0]=1;
	LL t=0;
//	t=log10(n); 这东西四舍五入取整 
	LL tmp=n;
	while(tmp) {
		t++;tmp/=10ll;
	}
	t--;
	for(LL i=1;i<=t+5;i++) tenth[i]=(tenth[i-1]*10)%m;
	Matrix nxt,st;
	st.h=1;st.l=3;
	st.val[1][1]=0;
	st.val[1][2]=st.val[1][3]=1;
	nxt.h=nxt.l=3;
	for(LL i=1;i<=t+1;i++) {
		nxt.val[1][1]=tenth[i];
		nxt.val[1][2]=nxt.val[1][3]=nxt.val[3][1]=nxt.val[2][3]=0;
		nxt.val[2][1]=nxt.val[2][2]=nxt.val[3][2]=nxt.val[3][3]=1;
//		write(LL(min(LL(pow(LL(10),i)),LL(n+1))-pow(10ll,i-1)),'\n');
		if(n==1000000000000000000ll&&i==19) nxt=pow(nxt,n+1-pow(10ll,i-1));//!!!!!!!用pow会爆 
		else nxt=pow(nxt,min(LL(powl(LL(10),i)),LL(n+1))-powl(10ll,i-1));
		st=st*nxt;
//		write(st.val[1][2],st.val[1][3],'\n');
	}
	write(st.val[1][1]%m);
	return 0;
}
//1000000000000000000 9
//111111111111111111 9
