/*** 
 * @Author: ltt
 * @Date: 2023-08-13 17:35:53
 * @LastEditors: ltt
 * @LastEditTime: 2023-08-13 17:36:03
 * @FilePath: std.cpp
*/
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN (100010 + 10)
#define INF (5000*5000*2)
using namespace std;
 
struct edge{
    int to, cost;
    edge(int tv = 0, int tc = 0):
        to(tv), cost(tc){}
};
typedef pair<int ,int> P;
int N, R;
vector<edge> graph[MAXN];
int dist[MAXN];     //最短距离
int dist2[MAXN];    //次短距离
 
void solve(){
    fill(dist, dist+N, INF);
    fill(dist2, dist2+N, INF);
    //从小到大的优先队列
    //使用pair而不用edge结构体
    //是因为这样我们不需要重载运算符
    //pair是以first为主关键字进行排序
    priority_queue<P, vector<P>, greater<P> > Q;
    //初始化源点信息
    dist[0] = 0;
    Q.push(P(0, 0));
    //同时求解最短路和次短路
    while(!Q.empty()){
        P p = Q.top(); Q.pop();
        //first为s->to的距离，second为edge结构体的to
        int v = p.second, d = p.first;
        //当取出的值不是当前最短距离或次短距离，就舍弃他
        if(dist2[v] < d) continue;
        for(unsigned i = 0; i < graph[v].size(); i++){
            edge &e = graph[v][i];
            int d2 = d + e.cost;
            if(dist[e.to] > d2){
                swap(dist[e.to], d2);
                Q.push(P(dist[e.to], e.to));
            }
            if(dist2[e.to] > d2 && dist[v] < d2){
                dist2[e.to] = d2;
                Q.push(P(dist2[e.to], e.to));
            }
        }
    }
    printf("%d\n", dist2[N-1]);
}
 
int main(){
	freopen("second.in","r",stdin);
	freopen("second.out","w",stdout);
    int A, B, D;
    scanf("%d%d", &N, &R);
    for(int i = 0; i < R; i++){
        scanf("%d%d%d", &A, &B, &D);
        graph[A-1].push_back(edge(B-1, D));
        graph[B-1].push_back(edge(A-1, D));
    }
    solve();
    return 0;
}
