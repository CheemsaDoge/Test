#include <bits/stdc++.h>
using namespace std;
const int N=1e4+100;
int fa[N],n,m,i,j,k,t,s[N];
long long ans;
struct node
{
    int x,y,w;
} edge[N];
bool cmp(node a,node b)
{
    return a.w<b.w;//排序
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);//并查集
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<n;i++)
            scanf("%d%d%d",&edge[i].x,&edge[i].y,&edge[i].w);
        for(int i=1;i<=n;i++)
            fa[i]=i,s[i]=1;
        sort(edge+1,edge+n,cmp);
        ans=0;
        for(int i=1;i<n;i++)
        {
            int x=find(edge[i].x),y=find(edge[i].y),w=edge[i].w;
            if (x==y)//在同一个连通块之间了
                continue;
            ans+=(long long)(s[x]*s[y]-1)*(w+1);//计算最少路径
            fa[x]=y;//合并
            s[y]+=s[x];//计算连通块大小.
        }
        printf("%lld\n",ans);//输出答案
    }
    return 0;
}
