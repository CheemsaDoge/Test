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
		freopen("x.in","r",stdin);
		freopen("x.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=1e3+123;
/*---------------------------------pre------------------------------------*/
struct Point {
	LL x,y;
}p[MAXN];
struct Edge {
	int p1,p2;
	double dis;
	bool operator <(const Edge&b) const {return dis<b.dis;}
}e[MAXN*MAXN];
inline long double calc(Point a,Point b) {
	return __builtin_sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int totr,top;
int maxx,maxp,minn=2147483647,minp;
int fa[MAXN];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
signed main() {
//	_File();
	int n,m;read(n,m);
	for(int i=1;i<=m;i++) {
		top++;read(p[top].x,p[top].y);
		if(p[top].x<minn) minn=p[top].x,minp=top;
		if(p[top].x>maxx) maxx=p[top].x,maxp=top;
	}
	p[++top].x=0;p[top].y=p[minp].y;
	p[++top].x=n+1;p[top].y=p[maxp].y;
//	write(minp,maxp,'\n');
	for(int i=1;i<=top;i++) {
		for(int j=1;j<i;j++) {
			if(i==top&&j==top-1) break;
			if(i==top||i==top-1||j==top-1)  e[++totr].p1=i,e[totr].p2=j,e[totr].dis=calc(p[i],p[j])*2;
			else e[++totr].p1=i,e[totr].p2=j,e[totr].dis=calc(p[i],p[j]);
		}
	}
	int cnt=0;
	sort(e+1,e+1+totr);
//	for(int i=1;i<=totr;i++) {
//		printf("%d %d %lf\n",e[i].p1,e[i].p2,e[i].dis);	
//	}
	for(int i=1;i<=top;i++) fa[i]=i;
	for(int i=1;i<=totr;i++) {
		if(find(e[i].p1)!=find(e[i].p2)) {
			cnt++;
			fa[find(e[i].p1)]=find(e[i].p2);
			write(e[i].p1,e[i].p2,'\n');
			if(cnt==top-1) {
				printf("%.2lf",(e[i].dis/2.0));
				exit(0);
			}
		}
	}
	return 0;
}

