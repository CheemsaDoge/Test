/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=1e3+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define db double
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no solution")
/*---------------------------------pre------------------------------------*/
long long l[MAXN],r[MAXN];
long long a[MAXN];
long long s[MAXN];
int n;
long long ans=0,ll=0,rr=0;
int main()
{
	freopen("line.in","r",stdin);
	freopen("line.out","w",stdout);
	read(n);
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		read(a[i]);
		s[i]=s[i-1]+a[i];
		l[i]=r[i]=i;
	}
	for(int i=1;i<=n;i++)
		while(((l[i]-1)>0)&&a[l[i]-1]>=a[i])
			l[1ll*i]=l[l[i]-1];
	long long ww;
	for(int i=n;i>=1;i--)
	{
		while(((r[i]+1)<=n)&&a[r[i]+1]>=a[i])
			r[i]=r[r[i]+1];
		ww=a[i]*(s[r[i]]-s[l[i]-1]);
		if((ww>ans)||(ww==ans&&(r[i]-l[i]<rr-ll)))
		{
			ans=ww;
			ll=l[i];
			rr=r[i];
		}
	}
	write(ans);pc;
	write(ll);pk;write(rr);
}
