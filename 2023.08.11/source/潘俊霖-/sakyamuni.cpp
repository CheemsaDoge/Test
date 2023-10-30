/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=3012;const int MOD=1e9;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
int C[MAXN][MAXN];
int mi[16];
map<int,int>ceng;
long long fast_pow(int a,int x,int p) //fast_pow
{
	if(a%p==0) return 0;
	long long no=a,ans=1;
	while(x){
		if(x&1) ans=1ll*ans*no%p;
		x>>=1;no=1ll*no*no%p;
	}
	return ans;
}
int main() {
	freopen("sakyamuni.in","r",stdin);
	freopen("sakyamuni.out","w",stdout);	
	int zan=1;
	C[0][0]=1;
	for(int i=0;i<=15;i++) mi[i]=zan,ceng[zan]=i,zan*=2;
	for(int i=1;i<=3000;i++)
	{
		C[i][0]=1;
		for(int j=1;j<=i;j++) C[i][j]=(1ll*C[i-1][j]+C[i-1][j-1])%MOD;
	}
	int n,ce;
	while(1){
		read(n);
		if(!n) return 0;
		for(int i=0;i<=15;i++) if(mi[i]<=n) ce=i; else break;
		if(mi[ce]==n) printf("%d\n",n);
		else {
			printf("%d\n",C[mi[ce]][n-mi[ce]+1]);
		}
	}
	
	return 0;
}
//1 2 1 4 6 4 1 8 
//1 2 3 4 5 6 7 8
//2^28>9e6
//lower_bound >=
//c 16 30-16+1
