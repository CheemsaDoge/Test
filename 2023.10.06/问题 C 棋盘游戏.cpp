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
		freopen("x.in","r",stdin);
		freopen("x.out","w",stdout);
	}
}
using namespace OI_File;
using namespace CheemsaDoge;
typedef long long LL;
const int MAXN=2e5;
/*---------------------------------pre------------------------------------*/
char map[6][6];
char target[6][6];
int dx[5]={0,0,0,+1,-1};
int dy[5]={0,+1,-1,0,0};
std::unordered_map<LL,int>h;
LL calc() {
	LL ans=0;
	for(int i=1;i<=16;i++) ans=(ans<<1)+map[(int)ceil(1.00*i/4)][(i-1)%4+1];
	return ans;
}
LL max_step=92;
void dfs(LL dep) {
	if(dep>max_step) return void();
	LL va=calc();bool flag=1;
	if(h.find(va)!=h.end()) if(h[va]<=dep) return void();h[va]=dep;
	for(int x=1;x<=4;x++) 
		for(int y=1;y<=4;y++) {
			if(map[x][y]!=target[x][y]) {
				flag=0;
				for(int k=1;k<=4;k++) {
					int nx=x+dx[k],ny=y+dy[k];
					if(nx>4||nx<1||ny>4||ny<1) continue;
					if(map[nx][ny]!=map[x][y]) swap(map[nx][ny],map[x][y]),dfs(dep+1),swap(map[nx][ny],map[x][y]);
					if(dep>=max_step) return void();
			}
		}
	}
	if(flag) return max_step=min(dep,max_step),void();
}
signed main() {
//	_File();
	for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) read(map[i][j]),map[i][j]-='0';
	for(int i=1;i<=4;i++) for(int j=1;j<=4;j++) read(target[i][j]),target[i][j]-='0';
	dfs(0ll);
	write(max_step);
	return 0;
}

