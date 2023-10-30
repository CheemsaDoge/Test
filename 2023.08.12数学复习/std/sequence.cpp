#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],pr[100010],hz[100010],hzm[100010],N,ans;
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],N+=a[i],ans+=a[i]; // 统计原序列的和，答案至少为这个数字
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i]; // 先求前缀和
	for(int i=1;i<=n;i++) pr[i]=(-pr[i])*2; // 求修改前缀的贡献
	for(int i=n;i>=1;i--) hz[i]=hz[i+1]+a[i]; // 后缀和
	for(int i=1;i<=n;i++) hz[i]=(-hz[i])*2; // 后缀贡献
	for(int i=n;i>=1;i--) hzm[i]=max(hz[i],hzm[i+1]); // 后缀贡献的后缀最大值
	for(int i=0;i<=n;i++) ans=max(ans,N+pr[i]+hzm[i+1]); // O(n) 求出答案
	cout<<ans<<endl;
	return 0; 
}
