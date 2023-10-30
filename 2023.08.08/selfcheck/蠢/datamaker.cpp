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
const int MAXN=1e4+1145;
const int INF=2147483647ll;
#define ll long long
#define ri register int
#define rl register long long
int a[MAXN][MAXN];
const int p=2;
int t,n,k;
int main() {
	srand(time(0));
	a[0][0]=1;
	for(int i=1;i<=10000;i++)
	{
		a[i][0]=1;
		for(int j=1;j<i;j++)
			a[i][j]=(a[i-1][j-1]+a[i-1][j])%2;
		a[i][i]=1;
	}
	freopen("stupid.in","w",stdout);
	t=rand()%1000000+1;
	cout<<t<<endl;
	while(t--)
	{
		n=rand()%10000+1;
		k=rand()%n+1;
		printf("%d %d\n",n,k);
	}
	return 0;
}
