/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e6+1145;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pg putchar('/')
/*---------------------------------pre------------------------------------*/
int n,m;
int len;
int a[MAXN];
int sum,cnt[MAXN];
struct query{
	int l,r,id;
	bool operator<(const query &x) const {
		if (l / len != x.l / len) return l < x.l;
		return (l / len) & 1 ? r < x.r : r > x.r;
	}
}q[MAXM];
inline void add(int i) {
	sum+=cnt[i]==2?-1:cnt[i]==1?1:0;
	cnt[i]++;
}
inline void del(int i) {
	cnt[i]--;
	sum+=cnt[i]==2?1:cnt[i]==1?-1:0;
}
int ans1[MAXN];
struct TmpIN{
	int _x,_id;
}tmpin[MAXN];
bool TmpIN_cmp(TmpIN _a,TmpIN _b) {return _a._x<_b._x;}
inline void LSH()
{
	int _lst=0,_totr=0;
	sort(tmpin+1,tmpin+1+n,TmpIN_cmp);
	for(int i=1;i<=n;i++)
	{
		_totr+=tmpin[i]._x==_lst?0:1;
		a[tmpin[i]._id]=_totr;
		_lst=tmpin[i]._x;
	}
}
int main()
{
	freopen("nature.in","r",stdin);
	freopen("nature.out","w",stdout);
	read(n);read(m);
	if(m<=n) len=int(1.0*n/sqrt(m));
	else len=int(sqrt(n));
	for(int i=1;i<=n;i++) read(tmpin[i]._x),tmpin[i]._id=i;
	LSH();
	for(int i=1;i<=m;i++){
		read(q[i].l);read(q[i].r);q[i].id=i;
	}
	sort(q+1,q+1+m);
	for(int i=1,l=1,r=0;i<=m;i++)
	{
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans1[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++){
		write(ans1[i]);pc;
	}
	return 0;
}
