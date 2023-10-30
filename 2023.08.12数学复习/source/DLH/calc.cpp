/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MOD=1e9+7;const int N =200;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
ll n,m,f[N][N],jc[N],c[N][N];
char s[N];
void Pre()
{
    jc[0]=1;c[0][0]=1;
    for(int i=1;i<=100;++i) jc[i]=jc[i-1]*i%MOD;
    for(int i=1;i<=100;++i){
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
	
}
ll calc()
{
    for(int len=2;len<=n;++len)
	    for(int i=1;i+len-1<=n;++i)
	    {
	        int j=i+len-1;
	        for(int k=i;k<j;++k)
	        {
	            if(s[k]=='*') f[i][j]+=f[i][k]*f[k+1][j]%MOD*c[j-i-1][k-i];
	            else if(s[k]=='-') f[i][j]+=(f[i][k]*jc[j-k-1]-f[k+1][j]*jc[k-i])%MOD*c[j-i-1][k-i];
	            else f[i][j]+=(f[i][k]*jc[j-k-1]+f[k+1][j]*jc[k-i])%MOD*c[j-i-1][k-i];
	            f[i][j]%=MOD;
	        }
	    }
    return (f[1][n]+MOD)%MOD;
}
int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	Pre();
    read(n);
    for(int i=1;i<=n;++i){read(f[i][i]);for(int j=i+1;j<=n;++j) f[i][j]=0;}//input & initialize
    scanf("%s",s+1);//input
    printf("%lld",calc());//calc and output
	return 0;
}
