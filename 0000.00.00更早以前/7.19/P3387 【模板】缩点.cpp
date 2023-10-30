#include<bits/stdc++.h>
#define maxn 100001
#define maxm 500001
using namespace std;
struct node{
    int to,next,from;
}edge[maxm];
queue <int> q;
vector <int> cb[maxn];
vector <int> rdr[maxn];
int ans[maxn],totq,x,y,v,rd[maxn],u,n,m,sum,vis[maxn],dis_[maxn],dis[maxn];
int dfn[maxn],low[maxn],f[maxn],times,cntqq;
int stack_[maxn],heads[maxm],visit[maxn],cnt,tot,index_;
void add(int x,int y)		//����
{
    edge[++cntqq].next=heads[x];
    edge[cntqq].from=x;
    edge[cntqq].to=y;
    heads[x]=cntqq;
   	return;
}
void tuopu()				//��������
{
	for(int i=1;i<=tot;i++)	//��ʼ�� 
    {
        if(rd[i]==0)
        q.push(i);			//���Ϊ0�Ķ������� 
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans[++totq]=u;
        for(int i=1;i<=cb[u].size();i++)
        {
            v=cb[u][i-1];	//��Ϊvector�Ǵ�0��ʼ�ģ����Լ�1���������ļ�1Ҳһ�� 
            rd[v]--;
            if(rd[v]==0)q.push(v);
        }
    }
}
void tarjan(int x)			//tarjan��ǿ��ͨ����
{
    dfn[x]=low[x]=++times;
    stack_[++index_]=x;		//��дջ�ٺٺ� 
    visit[x]=1;
   	for(int i=heads[x];i!=-1;i=edge[i].next)
    {
        if(!dfn[edge[i].to])
        {
           	tarjan(edge[i].to);
            low[x]=min(low[x],low[edge[i].to]);
       	}
       	else 
        if(visit[edge[i].to])
        low[x]=min(low[x],dfn[edge[i].to]);
    }
    if(low[x]==dfn[x])
   	{
   		tot++;//ǿ��ͨ������� 
   		while(1)
       	{
       		vis[stack_[index_]]=tot;	//index_���ڵ�ǿ��ͨ������ţ�����ǰ�潲��belong 
       		dis_[tot]+=dis[stack_[index_]];	//ǿ��ͨ����Ȩֵ�ۼ� 
       		visit[stack_[index_]]=0;index_--;
       		if(x==stack_[index_+1])break;//��дջ�ٺٺ� 
       	}
    }
}
int main(){
    memset(heads,-1,sizeof(heads));
    int n,m,x,y;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    scanf("%d",&dis[i]);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
       	add(x,y);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i); 	//tarjan 
    for(int i=1;i<=cntqq;i++){			//���˽���
        if(vis[edge[i].from]!=vis[edge[i].to])
        {
            x=vis[edge[i].from];y=vis[edge[i].to];
			rd[y]++;cb[x].push_back(y);rdr[y].push_back(x);
        }
    }
    tuopu();
    for(int i=1;i<=tot;i++)				//dp
    {
        int w=ans[i];
        f[w]=dis_[w];
        for(int j=1;j<=rdr[w].size();j++)
        f[w]=max(f[w],f[rdr[w][j-1]]+dis_[w]);
    }
    for(int i=1;i<=tot;i++)				//���ͳ�ƴ� 
    sum=max(f[i],sum);
    printf("%d",sum); 
    return 0;
}//�ոպ�100�� 

