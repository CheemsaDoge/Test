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
int n,m,top;
char INmap[1145];
int map[200][50];
int mapState[200];
int num[2500],stk[2500];
int dp[102][300][300];
inline void datain(void()) {
	read(n,m);
	for(int i=1;i<=n;i++) {
		scanf("%s",INmap+1);
		for(int j=1;j<=m;j++) {
			if(INmap[j]=='H') mapState[i]+=1<<(j-1);
		}
	}
	return void();
}
inline bool check(int x) {
	if(x&(x<<1)||x&(x<<2)) return false;
	return true;
}
inline void ini(void()) {
	top=0;
	for(int i=0;i<(1<<m);i++) if(check(i)) stk[++top]=i;
	return void();
}
inline bool fit(int x,int k) {return x&mapState[k]?0:1;}
inline int count(int x) {
	int cnt=0;
	while(x) cnt++,x&=(x-1);
	return cnt;
}
int solve() {
	int ans=0;
	memset(dp,-1,sizeof(dp));
	for(int j=0;j<=top;j++) {
		num[j]=count(stk[j]);
		if(fit(stk[j],1)) {
			dp[1][j][0]=num[j];
			ans=max(ans,dp[1][j][0]);
		}
	}
	for(int i=2;i<=n;i++) {
		for(int j=0;j<=top;j++) {
			if(!fit(stk[j],i)) continue;
			for(int k=0;k<=top;k++) {
				if(stk[j]&stk[k]) continue;
				for(int t=0;t<=top;t++) {
					if(stk[j]&stk[t]) continue;
					if(dp[i-1][k][t]==-1) continue;
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][k][t]+num[j]);
				}
				if(i==n) ans=max(ans,dp[i][j][k]);
			}
		}
	}
	return ans;
}
signed main() {
//	_File();
	datain(NULL);
	ini(NULL);
	write(solve());
	return 0;
}

