#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;
	T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
#define ll long long
#define ri register int
#define rl register long long
const int MAXN=1e6+1145;
int dp[70][70];
char a[70];
int main() {
	std::ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("color.in","r",stdin);
	freopen("color.out","w",stdout);
	cin>>a;
	memset(dp,0x3f,sizeof(dp));
	ri n=strlen(a);
	for(ri i=0; i<n; i++)
		dp[i][i]=1;
	for(ri len=2; len<=n; len++) {
		for(ri i=0; i<n-len+1; i++) {
			int j=i+len-1;
			for(ri k=i; k<j; k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]-(a[i]==a[k+1]));
		}
	}
	printf("%d",dp[0][n-1]);
}









//大力猴怎么回来了（恼 
//shilaibujifanyongdepaomo 19
//nidexiangweixuanzaibankong 20
