#include<cstdio>
#include<algorithm>
using namespace std;
 
int T,n,m;
int arr[100000];
int p1[100000];
int p2[100000];
int deg[100000];
 
int main(void)
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout); 
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			deg[i]=0;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&p1[i],&p2[i]);
			p1[i]--; p2[i]--;
			deg[p1[i]]++; deg[p2[i]]++;
		}
		int ans=20000000;
		if(m%2==0) ans=0;
		for(int i=0;i<n;i++)
			if((m-deg[i])%2==0)
				ans=min(ans,arr[i]);
		for(int i=0;i<m;i++)
			if((m-deg[p1[i]]-deg[p2[i]]+1)%2==0)
				ans=min(ans,arr[p1[i]]+arr[p2[i]]);
		printf("%d\n",ans);
	}
	return 0;
}
