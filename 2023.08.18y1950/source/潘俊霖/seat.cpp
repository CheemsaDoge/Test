/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long int
#define pc putchar('\n')
#define pk putchar(' ')
const int laji=1e8;
/*---------------------------------pre------------------------------------*/
int c[500010],rk[500010],n;
ll ans;
struct point {
	int num,val;
} po[500010];
inline bool cmp(point q,point w) {
	if(q.val==w.val)
		return q.num<w.num;
	return q.val<w.val;
}
inline void fix(int p,int d) {
	for(; p<=n; p+=p&-p)
		c[p]+=d;
}
inline int getsum(int x) {
	int sum=0;
	for(; x; x-=x&-x)
		sum+=c[x];
	return sum;
}
unordered_map<string,int>num;
string name;
int l=-1,now;
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	freopen("seat.in","r",stdin);
//	freopen("seat.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		num.insert(make_pair(name,i));
	}
	for(int i=1;i<=n;i++)
	{
		cin>>name;
		po[i].val=num[name];
		po[i].num=i;
	}
	sort(po+1,po+1+n,cmp);
	for(int i=1; i<=n; i++)
		rk[po[i].num]=i;
	for(int i=1; i<=n; i++) {
		fix(rk[i],1);
		ans+=i-getsum(rk[i]);
	}
	write(ans);
	return 0;
}

//1 /lt n /le 2 /times 10^5
//1 2 3
//3 2 1
// 2 1 3
// 1 3 2
