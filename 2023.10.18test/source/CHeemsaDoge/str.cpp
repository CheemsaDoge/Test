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
namespace MATRIX {
	const int MAXH=200,MAXL=200;
	const int MOD=1e9+7;
	struct Matrix{
		int h,l;
		LL val[MAXH][MAXL];
		inline void ini() {for(int i=0;i<h;i++) for(int j=0;j<l;j++) val[i][j]=0;for(int i=0;i<=h;i++) val[i][i]=1;}
		inline void print() {for(int i=0;i<h;i++) {for(int j=0;j<l;j++) write(val[i][j]),putchar(' ');write('\n');}}
		inline void clear() {for(int i=0;i<=h;i++) for(int j=0;j<=l;j++) val[i][j]=0;}
	};
	Matrix operator *(const Matrix &a,const Matrix &b) {
		int nh=a.h;int nl=b.l;
		Matrix c;c.h=nh;c.l=nl;
		for(int i=0;i<nh;i++) {
			for(int j=0;j<nl;j++) {
				c.val[i][j]=0;
				for(int k=0;k<a.l;k++) c.val[i][j]+=a.val[i][k]*b.val[k][j]%MOD,c.val[i][j]=(c.val[i][j]+MOD)%MOD;
			}
		}
		return c;
	}
	Matrix pow(Matrix _a,LL _n) {
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
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
int n,m,p[105];
char s[105];
Matrix a;
int g[105][105];
void kmp() {
	p[1]=0;
	for(int i=2;i<=m;i++) {
		int j=p[i-1];
		while(s[j+1]!=s[i]&&j)j=p[j];
		if(s[j+1]==s[i])p[i]=j+1;
	}
	for(int i=0;i<=m-1;i++)
		for(int j='0';j<='9';j++) {
			int k=i;
			while(s[k+1]!=j&&k) k=p[k];
			if(s[k+1]==j) k++;
			g[i][k]++;
		}
}
Matrix cg;
signed main() {
	read(n,m);
	a.h=a.l=m;a.clear();a.val[0][0]=1;
	scanf("%s",s+1);
	kmp();cg.h=cg.l=m;
	for(int i=0;i<m;i++) for(int j=0;j<m;j++) cg.val[i][j]=g[i][j];
//	cg.print();
	cg=pow(cg,n);a=a*cg;
	LL ans=0;
	for(int i=0;i<=m-1;i++) ans=(ans+a.val[0][i])%MOD;
	write(ans);
	return 0;
}
