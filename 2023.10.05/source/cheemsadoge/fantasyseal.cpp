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
		freopen("fantasyseal.in","r",stdin);
		freopen("fantasyseal.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;
const int MAXV=1e6+123;
/*---------------------------------pre------------------------------------*/
int head[MAXV];
int cnt,n,m,ans;
struct part {
	int l,r,col;
	int nxt,pre;
	int nxtp,prep;
}a[MAXN];
inline void merge(int x,int y) {
	a[x].nxtp=a[y].nxtp;
	a[x].nxt=a[y].nxt;
	a[x].r=a[y].r;
	a[a[x].nxtp].prep=x;
	a[a[x].nxt].pre=x;
}
signed main() {
	_File();
	read(n,m);
	int lstc=-1,lstl=0,tmp;
	for(int i=1;i<=n;i++) {
		read(tmp);
		if(lstc==-1) lstc=tmp,lstl=i;
		else if(lstc!=tmp) {
			++cnt;
			a[cnt]=(part){lstl,i-1,lstc,0,head[lstc],0,cnt-1};
			a[head[lstc]].nxt=cnt;head[lstc]=cnt;
			lstc=tmp;lstl=i;
		}
	}
	++cnt;
	a[cnt]=(part){lstl,n,lstc,0,head[lstc],0,cnt-1};
	a[head[lstc]].nxt=cnt;head[lstc]=cnt;ans=cnt;
	for(int i=1;i<cnt;i++) a[i].nxtp=i+1;
	for(int j=1;j<=m;j++) {
		int od,nw;read(od,nw);
		if(ans==1) write(1,'\n');
		else if(!head[od]||od==nw) write(ans,'\n');
		else {
			if(!head[nw]) {
				for(int i=head[od];i;i=a[i].pre) a[i].col=nw;
				head[nw]=head[od];head[od]=0;
			}
			else {
				for(int i=head[od];i;i=a[i].pre) {
					if(a[a[i].nxtp].col==nw) merge(i,a[i].nxtp),ans--;
					if(a[a[i].prep].col==nw) merge(a[i].prep,i),ans--;
				}
			}
			write(ans,'\n');
		}
	}
	return 0;
}

