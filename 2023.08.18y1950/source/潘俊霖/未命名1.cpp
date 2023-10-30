/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;    //fast input
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
template<typename T> inline void write(T x) {
	static char q[65];
	int cnt=0;
	if(x<0)putchar('-'),x=-x;
	q[++cnt]=char(x%10),x/=10;
	while(x)q[++cnt]=char(x%10),x/=10;
	while(cnt)putchar(q[cnt--]+'0');
}
/*---------------------------------pre------------------------------------*/
unsigned long long c[500010],rk[500010],n;
unsigned long long ans;
struct point {
	unsigned long long num,val;
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
inline unsigned long long getsum(int x) {
	unsigned long long sum=0;
	for(; x; x-=x&-x)
		sum+=c[x];
	return sum;
}
int val;
int main() {
	read(n);
	for(int i=1; i<=n; i++) {
		read(val);
		po[i].val=val;
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
