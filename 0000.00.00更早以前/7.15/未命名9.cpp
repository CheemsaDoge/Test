#include <bits/stdc++.h>
using namespace std;
#define lowbit(x) x&(-x)
const int N=200000+100;
int a[N],c[N],n,m,i,j,k,ans[N],p[N],v[N];
inline int ask(int x)
{
    int ans=0;
    for(;x;x-=lowbit(x))
        ans+=c[x];
    return ans;
}
inline int add(int x,int y)
{
    for(;x<=n;x+=lowbit(x))
        c[x]+=y;
}
int main()
{
	freopen("ticket.in","r",stdin);
//	freopen("ticket.out","w",stdout);
    ios::sync_with_stdio(false);
    while(cin>>n)
    {
        memset(c,0,sizeof(c));
        for(int i=1;i<=n;i++)
        {
            cin>>p[i]>>v[i];
            p[i]++;
            add(i,1);
        }
        for(int i=n;i>=1;i--)
        {
            int l=1,r=n;
            while(l<r)
            {
                int mid=(l+r)>>1;
                if (ask(mid)<p[i])
                    l=mid+1;
                else
                    r=mid;
            }
            ans[r]=v[i];
            add(r,-1);
        }
        for(i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}

