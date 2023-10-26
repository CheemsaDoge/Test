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
		freopen("sixarts.in","r",stdin);
		freopen("sixarts.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5+11451;
/*---------------------------------pre------------------------------------*/
int n,m;
int sum[MAXN];
int add[MAXN];
std::unordered_set<int>e[MAXN];
signed main() {
	_File();
	read(n,m);
	char op;int x,y;
	for(int j=1;j<=m;j++) {
		read(op,x);
		if(op=='*') {
			if(!e[x].empty()) add[x]++;
		} else {
			read(y);
			if(op=='?') {
				sum[x]+=add[y];sum[y]+=add[x];
				e[x].erase(y);e[y].erase(x);
			}else {
				if(!e[x].empty()) for(int i : e[x]) sum[i]+=add[x];
				if(!e[y].empty()) for(int i : e[y]) sum[i]+=add[y];
				e[x].insert(y);e[y].insert(x);
				add[x]=add[y]=0;
			}
		}
	}
	for(int i=1;i<=n;i++) if(!e[i].empty()) for(int d : e[i]) sum[d]+=add[i];
	for(int i=1;i<=n;i++) write(sum[i]),putchar(' ');
	return 0;
}

