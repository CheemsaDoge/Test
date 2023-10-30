/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define MOD 10007
/*---------------------------------pre------------------------------------*/
int a[MAXN];
int f[MAXN];
int ans,n;
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("thair.in","r",stdin);
	freopen("thair.out","w",stdout);
	read(n);
	int tag;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=n;i>=1;i--)
	{
		tag=-1;
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]<a[j]) f[i]++,ans+=f[j];
		}
	}
	write(ans);
	
}

//1 /lt n /le 2 /times 10^5
