/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=3e5+1145;const int MAXN=2000;const long long int INF=576460752303423488ll;//2^59
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
struct Edge{
	int u,v,val,nxt;
}edge[MAXM];
int head[MAXN],totr;
void add_edge(int u,int v,int val)
{
	edge[++totr].nxt=head[u];
	edge[totr].u=u;
	edge[totr].v=v;
	edge[totr].val=val;
	head[u]=totr;
}
int n,m;
void Tarjan(int u) {
    dfn[u] = low[u] = ++tc;
    vis[u] = 1;
    stk[++top] = u;

    for (int i = head[u]; i; i = d[i].n) {
        int v = d[i].b;

        if (vis[v] == 2)
            continue;

        if (!vis[v])
            Tarjan(v);

        low[u] = min(low[u], low[v]);
    }

    if (low[u] == dfn[u]) {
        cnt++;
        int v;

        while (v ^ u) {
            v = stk[top--];
            bel[v] = cnt;
            vis[v] = 2;
        }
    }
}

int main()
{
	read(n);read(m);
	
	return 0;
}


