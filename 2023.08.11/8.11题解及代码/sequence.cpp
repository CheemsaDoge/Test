#include<bits/stdc++.h>
using namespace std;
long long n,a[100010],pr[100010],hz[100010],hzm[100010],N,ans;
int main(){
	freopen("sequence.in", "r", stdin);
	freopen("sequence.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],N+=a[i],ans+=a[i]; // ͳ��ԭ���еĺͣ�������Ϊ�������
	for(int i=1;i<=n;i++) pr[i]=pr[i-1]+a[i]; // ����ǰ׺��
	for(int i=1;i<=n;i++) pr[i]=(-pr[i])*2; // ���޸�ǰ׺�Ĺ���
	for(int i=n;i>=1;i--) hz[i]=hz[i+1]+a[i]; // ��׺��
	for(int i=1;i<=n;i++) hz[i]=(-hz[i])*2; // ��׺����
	for(int i=n;i>=1;i--) hzm[i]=max(hz[i],hzm[i+1]); // ��׺���׵ĺ�׺���ֵ
	for(int i=0;i<=n;i++) ans=max(ans,N+pr[i]+hzm[i+1]); // O(n) �����
	cout<<ans<<endl;
	return 0; 
}
