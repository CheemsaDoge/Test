#include<cstdio>
#include<cstring>
int n,pr[5]={11261,19997,22877,21893,14843},qm[105][5],jl[1000005];
bool vis[5][30005];
char c[10005];
int f(int a,int b,int c)
{
    if(a==n) return qm[n][b];
    return (qm[a][b]+f(a+1,b,c)*c%pr[b])%pr[b];
}
int main()
{
	freopen("equation2.in", "r", stdin);
	freopen("equation2.out", "w", stdout);
    int m,ans=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;++i)
    {
        scanf("%s",c);
        int l=strlen(c),f=c[0]=='-'?1:0;
        for(int j=0;j<5;++j)
        {
            for(int k=f;k<l;++k)
                qm[i][j]=(qm[i][j]*10+c[k]-'0')%pr[j];
            if(f) qm[i][j]=-qm[i][j];
        }
    }
    for(int i=0;i<5;++i)
        for(int j=0;j<pr[i];++j)
            if(f(0,i,j)) vis[i][j]=1;
    for(int i=1;i<=m;++i)
    {
        bool sf=1;
        for(int j=0;j<5;++j)
            if(vis[j][i%pr[j]]) sf=0;
        if(sf) jl[ans++]=i;
    }
    printf("%d\n",ans);
    for(int i=0;i<ans;++i) printf("%d\n",jl[i]);
    return 0;
}
