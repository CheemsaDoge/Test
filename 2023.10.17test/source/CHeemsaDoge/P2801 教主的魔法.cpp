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
#undef std
using namespace OI_File;
typedef long long LL;
typedef __int128_t int128;
const int MAXN=2e6;const int MOD=998244353;const int MAXS=2e3;
/*---------------------------------pre------------------------------------*/
int n,q,l,r,w;
int L[MAXS],R[MAXS],a[MAXN],b[MAXN],belong[MAXN],block,add[MAXS];char op;
inline void update(int x) {
	for(int i=L[x];i<=R[x];i++) b[i]=a[i];
	return sort(b+L[x],b+R[x]+1),void();
}
signed main() {
//	_File();
	read(n,q);
	int now=0;L[now]=1;block=__builtin_sqrt(n);
	for(int i=1;i<=n;i++) {
		read(a[i]);b[i]=a[i];belong[i]=now+1;
		if(!(i%block)) {
			R[++now]=i;
			sort(b+L[now],b+R[now]+1);
			L[now+1]=i+1;
		}
	}
	if(n%block) R[++now]=n;
	update(now);
	while(q--) {
		read(op,l,r,w);
		if(op=='A') {
			LL ans=0,ls=belong[l],lr=belong[r];
			if(ls==lr) {for(int i=l;i<=r;i++) if(a[i]+add[ls]>=w) ans++;}
			else {
				for(int i=ls+1;i<lr;i++) {ans+=R[i]-(std::lower_bound(b+L[i],b+R[i]+1,w-add[i])-b-1);}
				for(int i=l;i<=R[ls];i++) if(a[i]+add[ls]>=w) ++ans;
				for(int i=L[lr];i<=r;i++) if(a[i]+add[lr]>=w) ++ans;
			}
			write(ans,'\n');
		} else {
			if(l>r) swap(l,r);
			int ls=belong[l],rs=belong[r];
			if(ls==rs) {
				for(int i=l;i<=r;i++) a[i]+=w;
				update(ls);
			} else {
				for(int i=ls+1;i<rs;i++) add[i]+=w;
				for(int i=l;i<=R[ls];i++) a[i]+=w;
				for(int i=L[rs];i<=r;i++) a[i]+=w;
				update(ls);update(rs);
			}
		}
	}
	return 0;
}

