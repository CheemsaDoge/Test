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
		freopen("prz.in","r",stdin);
		freopen("prz.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5+10;
/*---------------------------------pre------------------------------------*/
int n,m,t;
long long a[MAXN];
long long minv[4*MAXN],sum[4*MAXN],maxv[4*MAXN];
int tag[4*MAXN];
long long add_tag[4*MAXN];
void Push_up(const int&o){
	int ls=o*2,rs=o*2+1;
	minv[o]=min(minv[ls],minv[rs]);
	maxv[o]=max(maxv[ls],maxv[rs]);
	sum[o]=sum[ls]+sum[rs];
}
void Build(int o,int l,int r){
	tag[o]=0;
	add_tag[o]=0;
	if(l==r) return minv[o]=maxv[o]=sum[o]=a[l],void();
	int mid=l+(r-l)/2;
	Build(o*2,l,mid);
	Build(o*2+1,mid+1,r);
	Push_up(o);
}
void Add_plus_tag(int o,int l,int r,long long v){
	add_tag[o]+=v;
	sum[o]+=1ll*(r-l+1)*v;
	minv[o]+=v;
	maxv[o]+=v;
}
void Add_reverse_tag(int o){
	tag[o]=(tag[o]+1)%2;
	sum[o]=-sum[o];
	minv[o]=-minv[o];
	maxv[o]=-maxv[o];
	add_tag[o]=-add_tag[o];
}
void Push_down(const int&o,const int&l,const int&r){
	int ls=o*2,rs=o*2+1,mid=l+(r-l)/2;
	if(tag[o]){
		Add_reverse_tag(ls);
		Add_reverse_tag(rs);
		Add_plus_tag(ls,l,mid,add_tag[o]);
		Add_plus_tag(rs,mid+1,r,add_tag[o]);
		tag[o]=0;
	}else{
		Add_plus_tag(ls,l,mid,add_tag[o]);
		Add_plus_tag(rs,mid+1,r,add_tag[o]);
	}
	add_tag[o]=0;
}
void Update(int o,int l,int r,int tl,int tr,long long v){	
	if(l==r) {
		maxv[o]=minv[o]=sum[o]=abs(sum[o]-v);
		return ;
	}
	if(tl<=l&&r<=tr){
		if(maxv[o]<=v) return Add_reverse_tag(o),Add_plus_tag(o,l,r,v),void();
		if(minv[o]>=v) return Add_plus_tag(o,l,r,-v),void();
	}
	Push_down(o,l,r);
	int mid=l+(r-l)/2;
	if(tl<=mid) Update(o*2,l,mid,tl,tr,v);
	if(mid<tr) Update(o*2+1,mid+1,r,tl,tr,v);
	Push_up(o);
}
long long Query(int o,int l,int r,int tl,int tr){
	if(tl<=l&&r<=tr) return sum[o];
	long long ret=0;
	int mid=l+(r-l)/2;
	Push_down(o,l,r); 
	if(tl<=mid) ret+=Query(o*2,l,mid,tl,tr);
	if(mid<tr) ret+=Query(o*2+1,mid+1,r,tl,tr);
	Push_up(o);
	return ret;
}
int main(){
	_File();
	read(t);while(t--){
		read(n,m);
		for(int i=1;i<=n;i++) read(a[i]);
		Build(1,1,n);
		for(int i=1;i<=m;i++){
			int type,l,r;
			read(type,l,r);
			if(type==1){
				long long x;
				read(x);
				Update(1,1,n,l,r,x);
			}
			else write(Query(1,1,n,l,r),'\n');
		}
	}
	return 0;
}
