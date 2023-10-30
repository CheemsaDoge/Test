/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=1e5+10;const int MAXN=1e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pg putchar('/')
/*---------------------------------pre------------------------------------*/
int n,m;
int len;
int a[MAXN];
ll sum,cnt[MAXN];
struct query{
	int l,r,id;
  bool operator<(const query &x) const {
    if (l / len != x.l / len) return l < x.l;
    return (l / len) & 1 ? r < x.r : r > x.r;
  }
}q[MAXM];
void add(int i) {
	sum+=cnt[i];
	cnt[i]++;
}
void del(int i) {
	cnt[i]--;
	sum-=cnt[i];
}
ll gcd(ll _a,ll _b) {return _b?gcd(_b,_a%_b):_a;}
ll ans1[MAXN],ans2[MAXN];

int main()
{
	freopen("pig.in","r",stdin);
	freopen("pig.out","w",stdout);
	read(n);read(m);
	len=sqrt(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=m;i++){
		read(q[i].l);read(q[i].r);q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		if(q[i].l==q[i].r) {ans1[q[i].id]=0;ans2[q[i].id]=1;continue;}
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans1[q[i].id]=sum;ans2[q[i].id]=1ll*(r-l+1)*(r-l)/2;
	}
	for(int i=1;i<=m;i++){
		if(ans1[i]!=0){
			ll g=gcd(ans1[i],ans2[i]);
			ans1[i]/=g,ans2[i]/=g;
		}else ans2[i]=1;
		write(ans1[i]),pg,write(ans2[i]),pc;
	}
	
}
