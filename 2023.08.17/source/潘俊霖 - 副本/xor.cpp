/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
const int laji=1e8;
/*---------------------------------pre------------------------------------*/

int n;
int a[MAXN];
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool re=1;
	read(n);
	for(int i=0;i<n;i++) read(a[i]);
	for(int i=1;i<=laji/n;i++)
	{
		re=1;
		for(int j=0;j<n;j++) if(j>=1&&(a[j]^i)<(a[j-1]^i)) re=0;
		if(re) {write(i);return 0;} 
	}

	write(-1);
	return 0;
}

//1 /lt n /le 2 /times 10^5
