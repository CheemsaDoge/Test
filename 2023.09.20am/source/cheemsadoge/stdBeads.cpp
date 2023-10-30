#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int pp=13331,N=2e5+10;
int a[N];
set<ull>v;
ull p[N];
int ans[N],cnt;
ull s[N];
ull s1[N];
int n;
ull get(ull a[],int l,int r)
{
    return a[r]-a[l-1]*p[r-l+1];
}
ull get1(ull a[],int l,int r)
{
    return a[l]-a[r+1]*p[r-l+1];
}
int get_ans(int x)
{
    v.clear();
    for(int i=1;i+x-1<=n;i+=x)
    {
        int r=i+x-1;
        ull t=min(get(s,i,r),get1(s1,i,r));
        v.insert(t);
    }
    return  (int)v.size();
}
[[maybe_unused]]inline void _File(){
	freopen("Beads.in","r",stdin);
	freopen("Beads.ans","w",stdout);
}
int main()
{
	_File();
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    p[0]=1;
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]*pp+a[i];
        p[i]=p[i-1]*pp;
    }
    for(int i=n;i;i--)
    {
        s1[i]=s1[i+1]*pp+a[i];
    }
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        int t=get_ans(i);
        if(t==sum) ans[++cnt]=i;
        else if(t>sum)
        {
            sum=t,cnt=0;
            ans[++cnt]=i;
        }
    }
    cout<<sum<<' '<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
        cout<<ans[i]<<' ';
    return 0;
}
