#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}
long long n,m,q;
set<int>::iterator it;
const long long maxm = 5e5+1145;
const long long maxn = 3e5+1145;
set<int> Q[1111111];
struct edge{
    long long u,v,cost;
}es[maxm];
bool operator <(edge a,edge b){
    return a.cost > b.cost;
}
long long ans[maxm];
long long fa[maxn];
long long find(long long x){
    return x == fa[x]?x:fa[x]=find(fa[x]);
}
int main(){
    memset(ans,-1,sizeof(ans));
    for(long long i = 1;i < maxn;++i)
        fa[i] = i;
    scanf("%d%d",&n,&m);
    for(long long i = 0;i < m;++i)	read(es[i].u),read(es[i].v),read(es[i].cost);
    scanf("%d",&q);
    sort(es,es+m);
    for(long long i = 0;i < q;++i){
        long long x,y;
        scanf("%d%d",&x,&y);
        Q[x].insert(i);
        Q[y].insert(i);
    }
    for(long long i = 0;i < m;++i){
        long long x = es[i].u,y = es[i].v,c = es[i].cost;
        long long px = find(x),py = find(y);
        if(px == py) continue;
        else{
            if(Q[px].size() > Q[py].size())
                swap(px,py);
            vector<long long> tmp;
            for(it = Q[px].begin();it != Q[px].end();++it){
                long long id = *it;
                if(Q[py].count(id)){
                    ans[id] = c;
                    tmp.push_back(id);
                }
                Q[py].insert(id);
            }
            for(long long i = 0;i < tmp.size();++i)
                Q[py].erase(tmp[i]);
            fa[px] = py;
        }
    }
    for(long long i = 0;i < q;++i)
    	if(ans[i]==-1)
    		printf("impossible\n");
    	else
        	printf("%d\n",ans[i]);
}
