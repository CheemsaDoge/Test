/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=5e5+10;const int MAXN=1e4+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int k, tot;
bool vis[1<<14][2];
void dfs(int u) {
    for (int i=0;i<=1;i++) {
        if(vis[u][i]) continue;
        vis[u][i]=true;
        putchar(i+'0');
        int v=((u<<1)&tot)|i;
        dfs(v);
    }
}
int main() {
	read(k);
    tot=(1<<(k-1))-1;
    write(1<<k);pk;
    dfs(tot);
    return 0;
}
