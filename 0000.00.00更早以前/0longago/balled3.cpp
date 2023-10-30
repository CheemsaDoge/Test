#include<bits/stdc++.h>
using namespace std;
const int MAXN = 306;
const int MAXM = 306 * 306;//n - m   300
int n,m,fa[MAXN],val[MAXN],w[MAXN];
namespace subtask1{
	int Solve(){
		int ret = 0;
		bool hv[MAXN];
		for(int stat = 0;stat < (1<<n);stat++){
			for(int j = 1;j <= n;j++){
				hv[j] = (stat & (1 << (j-1)));
			}
			bool able = 1;
			int sumw = 0,sval = 0;
			for(int j = 2;j <= n;j++){
				if(hv[j] && hv[fa[j]] == 0){
					able = 0;
					break;
				}
				if(hv[j]){
					sumw += w[j];
					sval += val[j];
				}
			}
			
			if(able == 0)continue;
			if(sumw <= m)ret = max(ret,sval);
		}
		return ret;
	}
}
int main(){
	freopen("ballad.in","r",stdin);
//	freopen("ballad.out","w",stdout);
	cin>>n>>m;
	for(int i = 2;i <= n;i++){
		cin>>fa[i];
	}
	for(int i = 1;i <= n;i++){
		cin>>w[i]>>val[i];
	}
	if(n <= 11){
		cout<<subtask1::Solve();
	}
	return 0;
}
