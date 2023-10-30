#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e7+1145;
int va[MAXN];
int main(){
	freopen("D10.in","r",stdin);
	freopen("D10.ans","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&va[i]);
	int opt;
	int l,v,r;
	for(int i=1;i<=n;i++)
	{
		int ans=0;
		scanf("%d%d%d",&l,&r,&v);
		for(int j=l;j<=r;j++)
		{
			if(va[j]==v)	ans++;
			va[j]=v;
		}
		printf("%d\n",ans);
	}
	return 0;
}
