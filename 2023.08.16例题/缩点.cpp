///*code by 七枪六马五分钟四把三人两倒下一把*/
//#include <bits/stdc++.h>
//using namespace std;
//template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
//template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=x%10,x/=10;while(x)q[++cnt]=x%10,x/=10;while(cnt)putchar(q[cnt--]+'0');}
//const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
//#define db double
//#define ll long long
//#define pc putchar('\n')
//#define pk putchar(' ')
//#define pn puts("no")
///*---------------------------------pre------------------------------------*/
//struct EDGE{
//	int u,v,val,nxt;
//	bool tr;
//}edge[MAXM*2];
//int head[MAXN],totr;
//void add_edge(int u,int v){
//	edge[++totr].u=u;
//	edge[totr].v=v;
//	edge[totr].nxt=head[u];
//	head[u]=totr;
//}
//EDGE e[MAXM];int head2[MAXN],totr2;
//void add_edge2(int u,int v){
//	e[++totr2].u=u;
//	e[totr2].v=v;
//	e[totr2].nxt=head2[u];
//	head2[u]=totr2;
//}
//int low[MAXN],dfn[MAXN],dfs_num,num,scc[MAXN],siz[MAXN],scval[MAXN],val[MAXN];
//bool vis[MAXN],in_stack[MAXN];
//stack<int>sta;
//void Tarjan(int u)
//{
//	low[u]=dfn[u]=++dfs_num;in_stack[u]=1;
//	vis[u]=true;sta.push(u);
//	for(int i=head[u];i;i=edge[i].nxt)
//	{
//		#define v edge[i].v
//		if(!vis[v]){
//			Tarjan(v);low[u]=min(low[v],low[u]);
//		}
//		else if(in_stack[v])low[u]=min(low[u],dfn[v]);
//		#undef v
//	}
//	if(dfn[u]==low[u]){
//		++num;
//		while(sta.top()!=u)
//		{
////			write(sta.top());pk;
//			scval[num]+=val[sta.top()];
//			scc[sta.top()]=num;
//			in_stack[sta.top()]=false;
//			siz[num]++;
//			sta.pop();
//		}
////		write(sta.top());pk;
//		scval[num]+=val[sta.top()];
//		scc[sta.top()]=num;
//		in_stack[sta.top()]=false;
//		siz[num]++;
//		sta.pop();
////		pc;
//	}
//	
//}
//int rd[MAXN],cd[MAXN];
//bool vvis[MAXN];
//void dfs(int u)
//{
//	vvis[u]=1;
//	#define v edge[i].v
//	for(int i=head[u];i;i=edge[i].nxt)
//	{
//		if(vvis[v]) continue;
//		if(scc[u]!=scc[v]) add_edge2(scc[u],scc[v]),rd[scc[v]]++,cd[scc[u]]++;
//		dfs(v);
//	}
//	#undef v
//}
//
//int topo()
//{
//	stack<int>stac;int ans=0;
//	for(int i=1;i<=num;i++) if(!rd[i]) stac.push(i);
//	while(!stac.empty())
//	{
//		int u=stac.top();stac.pop();
//		ans=max(ans,scval[u]);
//		for(int j=head2[u];j;j=e[j].nxt)
//		{
//			scval[e[j].v]+=scval[u];
//			rd[e[j].v]--;
//			if(!rd[e[j].v]) stac.push(e[j].v);
//		}
//	}
//	return ans;
//}
//int main() {
////	freopen("ans.ans","w",stdout);
////	ios::sync_with_stdio(0);
////	cin.tie(0);
//	int n,m,u,v;
//	read(n);read(m);
//	for(int i=1;i<=n;i++) read(val[i]);
//	for(int i=1;i<=m;i++)
//	{
//		read(u);read(v);
//		add_edge(u,v);
//	}
//	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
//	for(int i=1;i<=n;i++) if(!vvis[i]) dfs(i);
//	write(topo());
//}
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
void add(int x,int y)       //建边
{
    edge[++cntqq].next=heads[x];
    edge[cntqq].from=x;
    edge[cntqq].to=y;
    heads[x]=cntqq;
    return;
}
void tuopu()                
{
    for(int i=1;i<=tot;i++) 
    {
        if(rd[i]==0)
        q.push(i);        
    }
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        ans[++totq]=u;
        for(int i=1;i<=cb[u].size();i++)
        {
            v=cb[u][i-1];
            rd[v]--;
            if(rd[v]==0)q.push(v);
        }
    }
}
void tarjan(int x)          //tarjan求强连通分量
{
    dfn[x]=low[x]=++times;
    stack_[++index_]=x;     //手写栈嘿嘿嘿 
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
            vis[stack_[index_]]=tot;    //index_所在的强连通分量编号，等于前面讲的belong 
            dis_[tot]+=dis[stack_[index_]]; //强连通分量权值累加 
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
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);  //tarjan 
    for(int i=1;i<=cntqq;i++){          //拓扑建边
        if(vis[edge[i].from]!=vis[edge[i].to])
        {
            x=vis[edge[i].from];y=vis[edge[i].to];
            rd[y]++;cb[x].push_back(y);rdr[y].push_back(x);
        }
    }
    tuopu();
    for(int i=1;i<=tot;i++)             //dp
    {
        int w=ans[i];
        f[w]=dis_[w];
        for(int j=1;j<=rdr[w].size();j++)
        f[w]=max(f[w],f[rdr[w][j-1]]+dis_[w]);
    }
    for(int i=1;i<=tot;i++)             //最后统计答案 
    sum=max(f[i],sum);
    printf("%d",sum); 
    return 0;
}//刚刚好100行 
