#include<bits/stdc++.h>
using namespace std;
const int N = 25005, M = 100005;
int n, r, p, s;
struct edge{
    int to, wei;
}e[M];
vector<edge> G[N];
int dis[N], vis[N];
priority_queue<int> q;
void search(){
    memset(dis, 0x3f, sizeof(dis));
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    while(!q.empty()){
        int f = q.top(); q.pop(); vis[f] = 0;
        for(int i = 0; i < G[f].size(); i++){
            int v = G[f][i].to, w = G[f][i].wei;
            if(dis[v] > dis[f] + w){
                dis[v] = dis[f] + w;
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}
int main(){
    cin>>n>>r>>p>>s;
    for(int i = 1; i <= r; i++){
        int a, b, c;
        cin>>a>>b>>c;
        G[a].push_back((edge){b , c});
        G[b].push_back((edge){a , c});
    }
    for(int i = 1; i <= p; i++){
        int a, b, c;
        cin>>a>>b>>c;
        G[a].push_back((edge){b , c});
    }
    search();
    for(int i = 1; i <= n; i++){
        if(dis[i] != 0x3f3f3f3f){
            cout<<dis[i]<<endl;
        }
        else{
            cout<<"NO PATH"<<endl;
        }
    }
    return 0;
}
