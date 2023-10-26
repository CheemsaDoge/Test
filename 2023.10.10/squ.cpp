/*code by CheemsaDoge*/
#include<bits/stdc++.h>
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
		freopen("squ.in","r",stdin);
		freopen("squ.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;const LL INF=0x3f3f3f3f3f3f3f3f;
/*---------------------------------pre------------------------------------*/
LL n,x,y;
LL sumx[MAXN],sumy[MAXN];
struct node{
	LL x,y,fy,fx,i;
}z[MAXN];
bool cmpx(node a,node b) {return a.x<b.x;}
bool cmpy(node a,node b) {return a.y<b.y;}
signed main() {
	_File();
	read(n);
	for (int i=1;i<=n;i++) {
		read(x,y);z[i].i=i;
		z[i].x=x+y;z[i].y=x-y;
	}
	sort(z+1,z+n+1,cmpx);
	for (int i=1;i<=n;i++) {
		z[i].fx=i;
		sumx[i]=sumx[i-1]+z[i].x;
	}
	sort(z+1,z+n+1,cmpy);
	for (int i=1;i<=n;i++) {
		z[i].fy=i;
		sumy[i]=sumy[i-1]+z[i].y;
	}
	LL ans=INF;
	for (int i=1;i<=n;i++) {
		LL res=0;
		res=-sumx[z[i].fx]+z[i].x*z[i].fx-sumy[z[i].fy]+z[i].y*z[i].fy-sumx[z[i].fx]-z[i].x*(n-z[i].fx)+sumx[n]-sumy[z[i].fy]-z[i].y*(n-z[i].fy)+sumy[n];
		ans=min(ans,res);
	}
	write(ans/2);
	return 0;
}
