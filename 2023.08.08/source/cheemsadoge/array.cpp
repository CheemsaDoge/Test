#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {
	x=0;T w=1,ch=getchar();
	while(!isdigit(ch)&&ch!='-')ch=getchar();
	if(ch=='-')w=-1,ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	x=x*w;
}
int n,cnt0;
vector<int>a,b; 
int main()
{
	freopen("array.in","r",stdin);
	freopen("array.out","w",stdout);
	int t;read(t);while(t--){
		a.clear();cnt0=0;read(n);
		for(int i=1;i<=n;++i){
			int x;read(x);
			if(!x) ++cnt0;
			else a.push_back(x);
		}
		while(a.size()>1){
			b.clear();
			if(cnt0) b.push_back(a[0]),--cnt0;
			for(int i=1; i<a.size();i++){
				int cj=a[i]-a[i-1];
				if(!cj) ++cnt0;
				else b.push_back(cj);
			}
			sort(b.begin(),b.end());a=b;
		}
		printf("%d\n",!a.size()?0:a[0]);
	}
	return 0;
}
