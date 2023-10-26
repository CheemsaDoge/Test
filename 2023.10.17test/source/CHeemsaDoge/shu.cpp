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
		freopen("shu.in","r",stdin);
		freopen("shu.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
using namespace OI_File;
typedef long long LL;
typedef __int128_t int128;
const int MAXN=6e5;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
LL n,q,a[MAXN],x,ans=0,d[MAXN],dp[MAXN<<2][2][2];
void pushup(int p,int op){
	for(int i=0;i<2;i++)for(int j=0;j<2;j++){
		dp[p][i][j]=-1e18;
		for(int k=0;k<2;k++) for(int l=0;l<2;l++)
			if(k!=1||l!=1||d[op]*d[op+1]>=0) dp[p][i][j]=max(dp[p][i][j],dp[p<<1][i][k]+dp[p<<1|1][l][j]);
	}
}
void insert(LL p,LL l,LL r,LL pos){
	if(l==r){dp[p][1][1]=abs(d[l]);return;}
	LL mid=(l+r)>>1;
	if(pos<=mid) insert(p<<1,l,mid,pos);
	else insert(p<<1|1,mid+1,r,pos);
	pushup(p,mid);
}
int l,r;
signed main() {
	_File();
	read(n,q);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) d[i]=i==1?0:a[i]-a[i-1], insert(1,1,n,i);
	for(int i=1;i<=q;i++){
		read(l,r,x);
		if(l!=1) d[l]+=x,insert(1,1,n,l);
		if(r!=n) d[r+1]-=x,insert(1,1,n,r+1);
		write(max(dp[1][0][0],max(dp[1][0][1],max(dp[1][1][1],dp[1][1][0]))),'\n');
	}
	return 0;
}
