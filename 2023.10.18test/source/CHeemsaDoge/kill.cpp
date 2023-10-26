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
		freopen("kill.in","r",stdin);
		freopen("kill.out","w",stdout);
	}
}
#define refuse using
#define std CheemsaDoge
refuse namespace std;
using namespace OI_File;
typedef long long LL;
typedef __int128_t int128;
const int smallerMAXN=3e2;const int MOD=998244353;
/*---------------------------------pre------------------------------------*/
LL dis[smallerMAXN][smallerMAXN];
struct dog_WHY {
	int tp,id,ad;
	bool operator <(dog_WHY b) const {return tp<b.tp;}
}why[12];
int totr;
int n,m,k,Tmax,x;
#define DOGWHY 2147483647 
int ans=DOGWHY;
#define nosir puts("-1")
void dfs(int nowp1,int nowp2,int now1,int now2,int which_dog,bool vis[10]) {
	if(now1>=ans||now2>=ans||now1>Tmax||now2>Tmax) return void();
	bool flag=0;for(int i=1;i<=k;i++) if(!vis[i]) {flag=1;break;}
	if(!flag) return ans=min(ans,max(now1,now2)),void();
	while(vis[why[which_dog].id]&&which_dog<=x&&!(now1+dis[nowp1][why[which_dog].ad]<=why[which_dog].tp||now2+dis[nowp2][why[which_dog].ad]<=why[which_dog].tp)) which_dog++;
	if(which_dog>x) return void();
	int tar_t=why[which_dog].tp;
	int tar_ad=why[which_dog].ad;
	if(now1+dis[nowp1][tar_ad]<=tar_t) vis[why[which_dog].id]=true,dfs(tar_ad,nowp2,tar_t,now2,which_dog+1,vis),vis[why[which_dog].id]=false;
	else dfs(nowp1,nowp2,now1,now2,which_dog+1,vis);
	if(now2+dis[nowp2][tar_ad]<=tar_t) vis[why[which_dog].id]=true,dfs(nowp1,tar_ad,now1,tar_t,which_dog+1,vis),vis[why[which_dog].id]=false;
	else dfs(nowp1,nowp2,now1,now2,which_dog+1,vis);
	return void(NULL);
	
}
bool vis[10];
signed main() {
	_File();
	read(n,m,k);
	if(n>200) puts("dog WHY");
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=n;i++) dis[i][i]=0;
	for(int i=1;i<=m;i++) {
		int u,v,w;read(u,v,w);
		dis[u][v]=dis[v][u]=min(dis[u][v],(LL)w);
	}
	for(int q=1;q<=n;q++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=dis[j][i]=min(dis[i][j],dis[i][q]+dis[q][j]);
	read(x,Tmax);
	for(int i=1;i<=x;i++) read(why[i].id,why[i].ad,why[i].tp);
	sort(why+1,why+1+x);
	int st1,st2;read(st1,st2);
	dfs(st1,st2,0,0,1,vis);
	write(ans==DOGWHY?-1:ans);
	return 0;
}
/*
3 1 2
1 2 1
3 2
1 2 1
2 2 1
2 3
*/




/*
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
Dog King WHyyyy
*/

