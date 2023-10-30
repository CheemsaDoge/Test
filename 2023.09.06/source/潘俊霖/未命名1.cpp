#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int N=101,M=1001,MOD=31011;

//ԭͼ����Ȩ��ɢ��������ȱ�Ȩ�洢 
struct e
{
    int x,y,v;
} tp[M],mst[M];
vector<e> edge[M]; 
int cmp(e a,e b)
{
    return a.v<b.v;
}

bool is[M];

//���鼯 
int bcj[N],bel[N];
void init(int a)
{
	for(int i=1;i<=a;i++) bcj[i]=i;
}
int rt(int a)
{
    if(bcj[a]==a) return a;
    return bcj[a]=rt(bcj[a]);
}
bool uni(int a,int b)
{
    int p=rt(a),q=rt(b);
    if(p==q) return true;
    bcj[p]=q;
    return false;
}

//�������� �������ڽӡ��������� 
int n,deg[N][N],g[N][N],mat[N][N];

int treecnt()//������������շת�����˹��Ԫ 
{
    int i,j,k,ans=1;
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            while(mat[j][i])
            {
                int div=mat[i][i]/mat[j][i];
                for(k=i;k<n;k++) mat[i][k]=(mat[i][k]-1ll*mat[j][k]*div%MOD+MOD)%MOD;
                swap(mat[i],mat[j]);
                ans*=-1;
            }
            if(mat[i][i]==0) return 0;
        }
        ans=1ll*ans*mat[i][i]%MOD;
    }
    return (ans+MOD)%MOD;
}

int main()
{
    int a,b,i,j,k,tl=0,tmp=0,cnt=0;
    scanf("%d%d",&a,&b);
    init(a);
    for(i=0;i<b;i++) scanf("%d%d%d",&tp[i].x,&tp[i].y,&tp[i].v);
    sort(tp,tp+b,cmp);

    //kruskal 
    for(i=0;i<b;i++)
    {
        if(tp[i].v!=tmp) tl++,tmp=tp[i].v;
        edge[tl].push_back(tp[i]);
        if(uni(tp[i].x,tp[i].y)) continue;
        is[tl]=1,mst[cnt]=tp[i],mst[cnt++].v=tl;
    }
    if(cnt!=a-1)
    {
        printf("0");
        return 0;
    }

    //ͳ�ƴ� 
    int ans=1;
    for(i=1;i<=tl;i++)
    {
        //�����С��������û���õ��˱�Ȩ 
        if(!is[i]) continue;

		init(a);
        int siz=edge[i].size();
		n=0;
		
		//���������ϵı�ȫ�����ϲ�����
		for(j=0;j<cnt;j++)
		{
			if(mst[j].v==i) continue;
			uni(mst[j].x,mst[j].y);
		}
		for(j=1;j<=a;j++)
		{
			if(bcj[j]==j) bel[j]=++n;
		}
		for(j=1;j<=a;j++) bel[j]=bel[rt(j)];
		
        //��ԭͼ�д˱�Ȩ�ı�ȫ������ 
        for(j=0;j<siz;j++)
        {
            int bx=bel[edge[i][j].x],by=bel[edge[i][j].y];
            deg[bx][bx]++,deg[by][by]++;
            g[bx][by]++,g[by][bx]++;
        }

        for(j=1;j<=n;j++)
            for(k=1;k<=n;k++)
                mat[j][k]=deg[j][k]-g[j][k];
        ans=ans*treecnt()%MOD;

        //ɾ�����ϵı� 
        for(j=0;j<siz;j++)
        {
            int bx=bel[edge[i][j].x],by=bel[edge[i][j].y];
            deg[bx][bx]--,deg[by][by]--;
            g[bx][by]--,g[by][bx]--;
        }
    }
    printf("%d",ans);
    return 0;
}
