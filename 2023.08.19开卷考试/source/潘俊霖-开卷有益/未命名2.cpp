#include<bits/stdc++.h>
using namespace std;
#define il inline
#define re register
#define debug printf("Now is Line : %d\n",__LINE__)
#define file(a) freopen(#a".in","r",stdin);freopen(#a".out","w",stdout)
#define int long long
map<int,int>a;
il int read()
{
    re int x=0,f=1;re char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') x=x*10+c-48,c=getchar();
    return x*f;
}
il int quickpow(int a,int b,int k)
{
    re int r=1;
    while(b)
    {
        if(b&1) r=(r*a)%k;
        b>>=1;
        a=(a*a)%k;
    }
    return r;
}
il int exgcd(int a,int b,int&x,int&y)
{
    if(!b)
    {
        x=1,y=0;
        return a;
    }
    re int gcd=exgcd(b,a%b,y,x);
    y-=(a/b)*x;
    return gcd;
}
signed main()
{
    re int T=read(),k=read();
    if(k==1)
    {
        while(T--)
        {
            re int y=read(),z=read(),p=read();
            printf("%lld\n",quickpow(y,z,p));
        }
    }
    else if(k==2)
    {
        while(T--)
        {
            re int a=read(),b=read(),p=read(),x,y;
            re int gcd=exgcd(a,p,x,y);
            if(b%gcd) puts("Orz, I cannot find x!");
            else
            {
                re int temp=p/gcd;
                while(x<0) x+=temp;
                printf("%lld\n",((x*b/gcd)%temp+temp)%temp);
            }
        }
    }
    else
    {
        while(T--)
        {
            re int y=read(),z=read(),p=read();
            re int m=ceil(sqrt(p));
            if(y%p==0&&z)
            {
                puts("Orz, I cannot find x!");
                continue;
            }
            a.clear();
            re int now=z%p,f=quickpow(y,m,p);
            a[now]=0;
            for(re int i=1;i<=m;++i)
            {
                now=(now*y)%p;
                a[now]=i;
            }
            now=1;
            re int flag=1;
            for(re int i=1;i<=m;++i)
            {
                now=(now*f)%p;
                if(a[now])
                {
                    re int ans=(i*m-a[now])%p;
                    printf("%lld\n",(ans+p)%p);
                    flag=0;
                    break;
                }
            }
            if(flag) puts("Orz, I cannot find x!");
        }
    }
    return 0;
}
