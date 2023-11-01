/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-31 11:14:58
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-01 09:51:07
 * @FilePath: \TEST\template_Dinic.cpp
 * -----------Have you ever loved Why today?-----------
 * Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
const int MAXN=300;const int MOD=998244353;
namespace Graph {
    struct Edge {
        int u,v,nxt;
        LL w;
    }edge[20000];
    int head[MAXN],totr=1;
    inline void add_edge(int u,int v,LL w) {
        edge[++totr].nxt=head[u];
        head[u]=totr;
        edge[totr].u=u;
        edge[totr].v=v;
        edge[totr].w=w;
    }
} using namespace Graph;
namespace EK { /*namespace CheemsaDoge and Graph is necessary*/
    LL ans=0;
    int pre[MAXN],n,m,s,t;
    bool vis[MAXN];
    LL dis[MAXN];
    inline bool super_bfs() {
        std::queue<int>que;
        que.push(s);memset(vis,0,sizeof(vis));
        vis[s]=true;dis[s]=2147483647;
        while(!que.empty()) {
            int u=que.front();
            que.pop();
            for(int i=head[u];i;i=edge[i].nxt) {
                if(!edge[i].w) continue;
                int v=edge[i].v;
                if(vis[v]==1) continue;
                dis[v]=CheemsaDoge::min(dis[u],edge[i].w);
                pre[v]=i;que.push(v);vis[v]=true;
                if(v==t) return true;
            }
        }
        return false;
    }
    inline void update() {
        int u=t;
        while(u!=s) {
            int i=pre[u];
            edge[i].w-=dis[t];
            edge[i^1].w+=dis[t];
            u=edge[i].u;
        } return ans+=dis[t],void();
    }
    LL ve[300][330];
    inline void calc() {
        while(super_bfs()) update();
    }
} using namespace EK;
namespace Dinic { /*namespace CheemsaDoge and Graph is necessary*/
    int n,m,s,t,now[MAXN];LL dis[MAXN];
    const LL INF=2147483647;
    bool bfs() {
        for(int i=1;i<=n;i++) dis[i]=INF;
        std::queue<int>que;
        dis[s]=0;now[s]=head[s];que.push(s);
        while(!que.empty()) {
            int u=que.front();que.pop();
            for(int i=head[u];i;i=edge[i].nxt) {
                int v=edge[i].v;
                if(dis[v]!=INF||!edge[i].w) continue;
                dis[v]=dis[u]+1;que.push(v);
                now[v]=head[v];
                if(v==t) return bool(true);
            }
        }
        return bool(false);
    }
    LL dfs(int u,LL lst=2e18) {
        if(u==t) return lst;
        LL k,res=0;
        for(int i=now[u];i&&lst;i=edge[i].nxt) {
            now[u]=i;int v=edge[i].v;
            if(dis[v]!=dis[u]+1||!edge[i].w) continue;
            k=dfs(v,CheemsaDoge::min(lst,edge[i].w));
            if(k==0) dis[v]=INF;
            edge[i].w-=k;edge[i^1].w+=k;
            res+=k;lst-=k;
        }
        return res;
    }
    LL calc() {LL ans=0;while(bfs()) ans+=dfs(s); return ans;}
} using namespace Dinic;
