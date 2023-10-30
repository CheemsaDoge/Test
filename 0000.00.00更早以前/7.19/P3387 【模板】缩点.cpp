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
void add(int x,int y)		//建边
{
    edge[++cntqq].next=heads[x];
    edge[cntqq].from=x;
    edge[cntqq].to=y;
    heads[x]=cntqq;
   	return;
}
void tuopu()				//拓扑排序
{
	for(int i=1;i<=tot;i++)	//初始化 
    {
        if(rd[i]==0)
        q.push(i);			//入度为0的都进队列 
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans[++totq]=u;
        for(int i=1;i<=cb[u].size();i++)
        {
            v=cb[u][i-1];	//因为vector是从0开始的，所以减1，下面代码的减1也一样 
            rd[v]--;
            if(rd[v]==0)q.push(v);
        }
    }
}
void tarjan(int x)			//tarjan求强连通分量
{
    dfn[x]=low[x]=++times;
    stack_[++index_]=x;		//手写栈嘿嘿嘿 
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
   		tot++;//强连通分量编号 
   		while(1)
       	{
       		vis[stack_[index_]]=tot;	//index_所在的强连通分量编号，等于前面讲的belong 
       		dis_[tot]+=dis[stack_[index_]];	//强连通分量权值累加 
       		visit[stack_[index_]]=0;index_--;
       		if(x==stack_[index_+1])break;//手写栈嘿嘿嘿 
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
    for(int i=1;i<=cntqq;i++){			//拓扑建边
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
    for(int i=1;i<=tot;i++)				//最后统计答案 
    sum=max(f[i],sum);
    printf("%d",sum); 
    return 0;
}//刚刚好100行 

