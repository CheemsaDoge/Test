/*** 
 * @Author: error: git config user.name & please set dead value or install git
 * @Date: 2023-11-08 20:29:18
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-10 16:44:40
 * @FilePath: \TEST\出题\data v2.0\sbtarzan.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
/*SBTARZAN*/
#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
long long n,w[MAXN],b[MAXN],s[MAXN];
long long  f[MAXN][2];
vector<int>edge[MAXN];
inline void add_edge(int u,int v) {edge[u].emplace_back(v);}
void dfs(int u,int fath) {
    f[u][1]=s[u]*w[u]-b[u]*100;
    f[u][0]=0;
    for(int v:edge[u]) {
        if(v==fath) continue;
        dfs(v,u);
        f[u][1]+=f[v][0];
        f[u][0]+=max(f[v][1],f[v][0]);
    }
}
signed main() {
    freopen("sbtarzan25.in","r",stdin);
    freopen("sbtarzan25.ans","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>w[i]>>b[i]>>s[i];
        if(s[i]>100) s[i]=100;  //是的，这就是不合理的数据
    }
    for(int i=1;i<n;i++) {
        int tmp1,tmp2;cin>>tmp1>>tmp2;
        add_edge(tmp1,tmp2);add_edge(tmp2,tmp1);
    }
    dfs(1,-1);
    printf("%.2lf\n0\nCongratulations to player Hang for joining LCK!",max(f[1][1],f[1][0])/100.0);
}