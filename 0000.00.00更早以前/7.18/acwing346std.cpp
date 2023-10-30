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
    return a.w<b.w;//����
}
int find(int x)
{
    return fa[x]==x?x:fa[x]=find(fa[x]);//���鼯
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
            if (x==y)//��ͬһ����ͨ��֮����
                continue;
            ans+=(long long)(s[x]*s[y]-1)*(w+1);//��������·��
            fa[x]=y;//�ϲ�
            s[y]+=s[x];//������ͨ���С.
        }
        printf("%lld\n",ans);//�����
    }
    return 0;
}
