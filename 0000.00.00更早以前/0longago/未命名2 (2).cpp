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
//������Ѿ������⣬���Զ���int main()����ʼ�Ķ� 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>

#define N 2010

using namespace std;

int n,m,e,ans;
int vis[N][N];
int ask[N],matched[N];

inline bool found(int x){ //dfs������· 
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
    int cnt = 0;//cnt�Ǽ����� 
    memset(matched,0,sizeof(matched));
    for (int i = 1 ; i <= n ; i++){
      memset(ask,0,sizeof(ask));
      if (found(i)) 
	  	cnt++;	//�ҵ��˾ͼ�1 
    }
    ans = cnt;
}
//���������¿��� 
int main(){
    scanf("%d%d%d",&n,&m,&e);//�������ֱ�Ϊn,m������Ϊe
    for (int i = 1 ; i <= e ; i++){
      int x,y;
      scanf("%d%d",&x,&y);
      vis[x][y] = 1;
    }
    match();///�������㷨������ 
    printf("%d \n",ans);
    return 0;
}
