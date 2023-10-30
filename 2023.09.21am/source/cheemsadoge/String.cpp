/*code by CheemsaDoge*/
#include <bits/stdc++.h>
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
template <typename T> inline T min(const T a,const T b) {return a>b?b:a;}
template <typename T> inline T max(const T a,const T b) {return a>b?a:b;}
const int MAXM=606;const int MAXN=2000;const long long int INF=2147483647;//2^59
const int S=12,Q=2500003;
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
inline void _File(){
	freopen("String.in","r",stdin);
	freopen("String.out","w",stdout);
}
std::vector<int> g[MAXM];
int tot = 0, n, tr[MAXM][26], fail[MAXM], e[MAXM], cnt, su = 1 << 30;
char str[55], ans[MAXM], res[MAXM];
bool vis[MAXM][1 << S];
void insert(int id) {
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int o = str[i] - 'A';
        if (!tr[p][o])
            tr[p][o] = ++tot;
        p = tr[p][o];
    }
    e[p] |= 1 << id;
}
void build() {
    std::queue<int> q;
    for (int i = 0; i < 26; i++)
        if (tr[0][i]) {
            g[0].push_back(tr[0][i]);
            q.push(tr[0][i]);
        }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < 26; i++)
            if (tr[x][i]) {
                fail[tr[x][i]] = tr[fail[x]][i];
                g[tr[fail[x]][i]].push_back(tr[x][i]);
                q.push(tr[x][i]);
            } else
                tr[x][i] = tr[fail[x]][i];
    }
}
int q[Q], fq[Q], wq[Q], sq[Q], fr, tp;

void dfs(int x) {
    for (auto vv : g[x]) {
        e[vv] |= e[x];
        dfs(vv);
    }
}
void pr(int x) {
    if (x == 1)
        return;
    pr(fq[x]);
    putchar(wq[x] + 'A');
}
void bfs() {
    fr = 1;
    tp = 2;
    vis[0][0] = true;
    while (fr < tp) {
        int x = q[fr], set = sq[fr];
        for (int i = 0; i < 26; ++i)
            if (tr[x][i]) {
                if (vis[tr[x][i]][set | e[tr[x][i]]])
                    continue;
                wq[tp] = i;
                fq[tp] = fr;
                sq[tp] = set | e[tr[x][i]];
                q[tp] = tr[x][i];
                vis[q[tp]][sq[tp]] = true;
                if (sq[tp] == (1 << n) - 1) {
                    pr(tp);
                    return;
                }
                ++tp;
            }
        ++fr;
    }
}
int main() {
	_File();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", str);
        insert(i);
    }
    build();
    dfs(0);
    bfs();
    return 0;
}

