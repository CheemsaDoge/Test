#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int s = 0,w = 1;
    char g = getchar();
    while(g<'0'||g>'9'){if(g=='-')w*=-1;g = getchar();}
    while(g>='0'&&g<='9'){s = s*10+g-'0';g = getchar();}
    return s*w;
}
#define N 10010
int n,e,ans,m;
bool vis[N][N];
bool ask[N],matched[N];
bool w[N];
inline bool found(int x){
	int a[4];
	a[0]=x<=n?0:x-n;
	a[1]=x<=1?0:x-1;
	a[2]=x>=n*n-1?0:x+1;
	a[3]=x>=n*n-n?0:x+n;
    for (int i = 0; i <=3; i++)
      if (vis[x][a[i]]){
        if (ask[a[i]]||!a[i]) 
			continue;
        ask[a[i]] = 1;
        if (!matched[a[i]] || found(matched[a[i]])) { 
			matched[a[i]] = x ; 
			return true;
		}
      }
    return false;
}
inline void clear(){
	for(int i=0;i<=n*n;i++)
		ask[i]=0;
}
inline void match(){
    int cnt = 0;
    memset(matched,0,sizeof(matched));
    for (int i = 1 ; i <= n*n ; i+=2)
	    if(i%2)
	    {
	    	clear();
	    	if (found(i)) 
				cnt++;
		}
    ans = cnt;
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    n=read();
    m=read();
//    if(m==0)
//    {
//    	printf("%d",n*n/2);
//    	return 0;
//	}
    int a,b;
    for (int i = 1 ; i <= m ; i++){
      a=read();
      b=read();
      w[b*n-n+a]=1;
    }
    int n1=n*n;
    int n2=n1-n;
    for(int i=1;i<=n1;i++)
    	if(!w[i])
    	{
    		if(i%n!=0)	vis[i][i+1]=w[i+1]||i+1>n1?0:1,vis[i+1][i]=vis[i][i+1];
    		if(i<=n2)	vis[i][i+n]=w[i+n]||i+n>n1?0:1,vis[i+n][i]=vis[i][i+n];
		}
    match();
    printf("%d \n",ans);
    return 0;
}
