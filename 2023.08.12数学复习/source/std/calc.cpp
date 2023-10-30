#include <bits/stdc++.h>
using namespace std;
const int N=110,MOD=1e9+7;
long long f[N][N],fac[N],c[N][N];
char s[N];
int n;
void prepare()
{
    fac[0]=1;
    for(int i=1;i<=100;++i)
        fac[i]=fac[i-1]*i%MOD;
    c[0][0]=1;
    for(int i=1;i<=100;++i)
    {
        c[i][0]=1;
        for(int j=1;j<=i;++j)
        c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
    }
}
void work()
{
    for(int i=1;i<=n;++i)
    {
        scanf("%lld",&f[i][i]);
        for(int j=i+1;j<=n;++j)
            f[i][j]=0;
    }
    scanf("%s",&s[1]);
    for(int len=2;len<=n;++len)
    for(int i=1;i+len-1<=n;++i)
    {
        int j=i+len-1;
        for(int k=i;k<j;++k)
        {
            if(s[k]=='*')
                f[i][j]+=f[i][k]*f[k+1][j]%MOD*c[j-i-1][k-i];
            else if(s[k]=='+')
                f[i][j]+=(f[i][k]*fac[j-k-1]+f[k+1][j]*fac[k-i])%MOD*c[j-i-1][k-i];
            else
                f[i][j]+=(f[i][k]*fac[j-k-1]-f[k+1][j]*fac[k-i])%MOD*c[j-i-1][k-i];
            f[i][j]%=MOD;
        }
    }
    printf("%lld\n",(f[1][n]+MOD)%MOD);

}
int main()
{ 
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
    prepare();
    while(~scanf("%d",&n))
    work();
    return 0;
}
