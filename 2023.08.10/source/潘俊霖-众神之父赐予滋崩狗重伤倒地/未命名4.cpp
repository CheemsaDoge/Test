#include<cstring>
#include<algorithm>
using namespace std;
long long n,Max,S,a[100093],sum,ans;
inline long long read() {
	long long cnt=0,f=1;
	char ch=getchar();
	while (ch<'0'||ch>'9') {
		if (ch=='-')f=-1;
		ch=getchar();
	}
	while (ch>='0'&&ch<='9') {
		cnt=cnt*10+ch-48;
		ch=getchar();
	}
	return cnt*f;
}
int main() {
	n=read();
	for (int i=1; i<=n; i++) {
		a[i]=read();
		sum+=a[i];
	}
	for (int i=1; i<=n; i++)
		if (S+a[i]<0) S=0;
		else {
			S+=a[i];
			Max=max(Max,S);
		}
	Max=max(Max,S);
	ans=Max*2-sum;
	printf("%lld\n",ans);
	return 0;
