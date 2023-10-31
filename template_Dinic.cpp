/*
 * @Author: CheemsaDoge
 * @Date: 2023-10-31 11:14:58
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-10-31 21:20:37
 * @FilePath: \TEST\template_Dinic.cpp
 * -----------Have you ever loved Why today?-----------
 * Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include <bits/stdc++.h>

inline long long netflow(int s, int t, std::vector<std::vector<long long>> cap) {
    const long long INF = 0x3f3f3f3f3f3f3f3f;
    int n = (int)cap.size();
    std::vector<int> pre(n), cur(n, 0), dep(n, 0), num(n, 0);
    std::vector<long long> f(num[0] = n);
    int u = s;
    long long flow = INF, maxflow = 0;

    while (dep[u] < n) {
        f[u] = flow;
        bool ok = false;

        for (int v = cur[u]; v < n; v++) {
            if (!cap[u][v] || dep[u] != dep[v] + 1)
                continue;

            ok = true, pre[v] = u, cur[u] = v, flow = std::min(cap[u][v], flow), u = v;

            if (u == t) {
                maxflow += flow;

                while (u != s) {
                    cap[pre[u]][u] -= flow;
                    cap[u][pre[u]] += flow;
                    u = pre[u];
                }

                flow = INF;
            }

            break;
        }

        if (ok)
            continue;

        if (--num[dep[u]] == 0)
            break;

        int c = -1;

        for (int v = 0; v < n; v++)
            if (cap[u][v] && (c == -1 || dep[v] < dep[c]))
                c = v;

        cur[u] = c, num[dep[u] = (~c ? dep[c] : n) + 1]++;

        if (u != s)
            u = pre[u], flow = f[u];
    }

    return maxflow;
}
#define add_edge(u,v,w) cap[u - 1][v - 1] += w;
int main() {
    int n, m, s, t;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    std::vector<std::vector<long long>> cap(n, std::vector<long long>(n));
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        cap[u - 1][v - 1] += w;
    }

    printf("%lld\n", netflow(s - 1, t - 1, cap));
    return 0;
}


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
}using namespace Graph;
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
}
using namespace EK;

