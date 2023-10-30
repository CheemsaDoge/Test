#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

#define pb push_back
#define ll long long
#define N 210000
using namespace std;

map <ll,map<ll,ll> > mp;
vector <ll> e[N];
ll rd[N];
ll ans,sum;
ll n,m;
ll vis[N];
ll cnt=0;
void dfs(ll k)
{
	vis[k]=1;
	cnt++;
	for(ll v:e[k])
	{
		if(!mp[k][v])
		{
			rd[v]++;
			rd[k]++;
			if(rd[v]%2==1) sum++;else sum--;
			if(rd[k]%2==1) sum++;else sum--;
			mp[v][k]=1;
			mp[k][v]=1;
		}
		if(!vis[v]) dfs(v);
	}
}

int main()
{
	//ios::sync_with_stdio(0);
//	cin.tie(0);
	while(cin>>n>>m)
	{
		for(int i=1;i<=m;i++)
		{
			ll u,v;
			cin>>u>>v;
			e[u].pb(v);
			e[v].pb(u);
		}
		
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				sum=0;
				cnt=0;
				dfs(i);
				if(sum==0&&cnt!=1) ans++;
				else ans+=sum/2;
			}
		}
		cout<<ans<<"\n";
		for(int i=1;i<=n;i++) vis[i]=0,rd[i]=0,e[i].clear();
		ans=0;
		mp.clear();
	}
	return 0;
}
