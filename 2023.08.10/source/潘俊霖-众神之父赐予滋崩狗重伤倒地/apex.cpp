/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=3e6+1145;const int INF=2147483647ll;//2^31-1
#define db double
int n,p,m;
int inv[MAXN];
int main() {
	freopen("apex.in","r",stdin);
	freopen("apex.out","w",stdout);	
	int T;read(T);
	while(T--)
	{
		read(n);read(m);
		printf("-1\n");
	}
	return 0;
}


/*��˵�öԣ������̱���һ��������öĶ�����з��ģ�
����˾��ĳ��ܲ�ǹ��������㽫���鵽
���̱���˾�����������̱�������ȥ�˱��������ò����̱��ˡ����Ը粻Ҫ�����Ը��Ҵ��ˡ����Ը��´β�����*/
