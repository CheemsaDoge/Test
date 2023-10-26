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
		freopen("scarlet.in","r",stdin);
		freopen("scarlet.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
#define mp std::make_pair
LL a[500005][2];
LL n,m,p;
inline LL query(int pos) {
	LL sumA=0, sumB=0;
	for(int k=pos;k>0;k-=k&-k) sumA+=a[k][0],sumB+=a[k][1];
	return sumA*(pos+1)-sumB;
}
inline void add(int pos,LL x) {
	if(pos==0) return void();
	for(int k=pos;k<=n;k+=k&-k) a[k][0]+=x,a[k][1]+=x*pos;
}
signed main() {
	_File();
	read(n,m);
	for (int i=1;i<=n;++i) {
		read(a[i][0]);
		a[i][1]=a[i-1][1]+(a[i][0]-a[i-1][0])*i;
	}
	for (int i=n;i>= 1;--i) {
		a[i][0]-=a[(i-1)&i][0];
		a[i][1]-=a[(i-1)&i][1];
	}
	while(m--) {
		LL op,l,r,x;read(op,l,r);
		if(op==1) {
			read(x);
			if(r>=l-1) {
				add(1,x);add(n+1,-x);
			} else {
				for(p=0;l*p+1<=n;p++) {
					add(l*p+1,x);
					add(l*p+r+2,-x);
				}
			}
//			for(int i=1;i<=n;i++) write(query(i)-query(i-1),' ');
//			write('\n');
		} else {
			write(query(r)-query(l-1),'\n');
		}
	}
}
/*
6 7
1 1 4 5 1 4
2 1 5
1 1 4 5
2 1 5
1 3 2 1
2 4 6
1 4 2 2
2 1 6
Are you going to Scabrough Fair?
Parsley sage rosemary and thyme.
Remember me to one who lives ther.
He once was a true love of mine.
*/
