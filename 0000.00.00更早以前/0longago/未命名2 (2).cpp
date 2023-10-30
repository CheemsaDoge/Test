#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
inline ll read()
{
    ll io=0;
	char in=getchar();
    while(in<'0'||in>'9')in=getchar();
    while(in>='0'&&in<='9')io=(io<<3)+(io<<1)+(in^'0'),in=getchar();
    return io;
}
const int N = 1e3;
bool f[N][N];
bool used[N];
int match[N];
int n,m,e;

bool DFS(int pos)
{
    for(int i=1; i<=m; i++)
    {
        if(f[pos][i] && !used[i])
        {
            used[i] = true;
            if(!match[i] || DFS(match[i])) 
            {
                match[i] = pos;
                return true;
			}
        }
    }
    return false; 
}

int main()
{
    n=read();
    m=read();
    e=read();
    for(int i=1; i<=e; i++)
    {
        int x,y; scanf("%d%d",&x,&y);
        if(x<=n && y<=m) f[x][y] = true; 
    }
    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        memset(used,false,sizeof(used));
        if(DFS(i)) ans++;
    }
    printf("%d\n",ans);
    return 0;
}




/////////////////
//如果你已经读完题，请自动从int main()处开始阅读 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

#define N 2010

using namespace std;

int n,m,e,ans;
int vis[N][N];
int ask[N],matched[N];

inline bool found(int x){ //dfs找增广路 
    for (int i = 1 ; i <= m ; i++)
      if (vis[x][i]){
        if (ask[i]) 
			continue;
        ask[i] = 1;
        if (!matched[i] || found(matched[i])) { 
			matched[i] = x ; 
			return true;
		}
      }
    return false;
}

inline void match(){
    int cnt = 0;//cnt是计数器 
    memset(matched,0,sizeof(matched));
    for (int i = 1 ; i <= n ; i++){
      memset(ask,0,sizeof(ask));
      if (found(i)) 
	  	cnt++;	//找到了就加1 
    }
    ans = cnt;
}
//从这里向下看起 
int main(){
    scanf("%d%d%d",&n,&m,&e);//结点个数分别为n,m，边数为e
    for (int i = 1 ; i <= e ; i++){
      int x,y;
      scanf("%d%d",&x,&y);
      vis[x][y] = 1;
    }
    match();///匈牙利算法，见上 
    printf("%d \n",ans);
    return 0;
}
