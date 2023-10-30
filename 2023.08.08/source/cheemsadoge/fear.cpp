#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
const int MAXN=1e6+1145;
const int INF=2147483647ll;
#define ll long long
#define ri register int
#define rl register long long
int sum1,sum2,ww=0;
int a[200],b[200];
int main() {
	freopen("fear.in","r",stdin);
	freopen("fear.out","w",stdout);
	int n,k;
	read(n);read(k);
	if(n>=10) return 0;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) read(b[i]);
//	sum1+=a[i]>b[i]?1:0,sum2+=a[i]<b[i]?1:0;
//	if(sum1-sum2==k) ww++;
	while(next_permutation(a+1,a+1+n))
	{
		sum1=sum2=0;
		for(int i=1;i<=n;i++) sum1+=a[i]>b[i]?1:0,sum2+=a[i]<b[i]?1:0;
		if(sum1-sum2==k) ww++;
	}
	printf("%d\n",ww+1);
}
