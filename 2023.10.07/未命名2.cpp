#include<bits/stdc++.h>
using namespace std;
int n,m,k;
const int mo=1e6;
vector<int> v;
vector<int> can[1000];
int p[10];
int f[10005][800];
int b[15];
bool check(int s)
{
	int cnt=0;
	while (s>=0)
	{
		b[++cnt]=s%3;
		s/=3;
		if (s==0)
		{
			if (cnt<m) b[++cnt]=0;
			break;
		}
	}
	if (cnt!=m) return false;
	for (int i=1;i<m;i++)
		if (b[i]==b[i+1]) return false;
	return true;
}
int main()
{
	int i,j,l,x,sta=0;
	p[0]=1;
	for (i=1;i<=5;i++) p[i]=p[i-1]*3;
	scanf("%d%d",&n,&m);
	scanf("%d",&k);
	for (i=1;i<=m;i++) {
		scanf("%d",&x);
		sta=sta*3+x-1;
	}
	for (i=0;i<p[m];i++)
		if (check(i)) v.push_back(i);
	for (i=0;i<v.size();i++)
		for (j=0;j<v.size();j++)
		{
			bool flag=true;
			for (x=0;x<m;x++)
				if (v[i]/p[x]%3==v[j]/p[x]%3)
				{
					flag=false;
					break;
				}
			if (flag) can[v[i]].push_back(v[j]);
		}
	if(k==1) f[1][sta]=1;
	else for (j=0;j<v.size();j++)	f[1][v[j]]=1;
	for (i=2;i<=n;i++)
		if(i==k) for(j=0;j<can[sta].size();j++) f[i][sta]+=f[i-1][can[sta][j]],f[i][sta]%=mo;
		else for(j=0;j<v.size();j++) for(l=0;l<can[v[j]].size();l++) f[i][v[j]]+=f[i-1][can[v[j]][l]],f[i][v[j]]%=mo;
	int ans=0;
	if (k!=n) for(j=0;j<v.size();j++) ans+=f[n][v[j]],ans%=mo;
	else ans=f[n][sta];
	printf("%d\n",ans);
	return 0;
}
