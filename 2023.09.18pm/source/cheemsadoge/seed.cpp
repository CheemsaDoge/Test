/*code by CheemsaDoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char _q[65];int cnt=0;if(x<0)putchar('-'),x=-x;_q[++cnt]=char(x%10),x/=10;while(x)_q[++cnt]=char(x%10),x/=10;while(cnt)putchar(_q[cnt--]+'0');}
const int MAXM=1e6+1145;const int MAXN=1e6+11145;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
[[maybe_unused]]inline void _File(){
	freopen("x.in","r",stdin);
	freopen("x.out","w",stdout);
}
int WA,AC,tot;
int main(){
//	_File();
		while(1)
	{
		tot++;
		system("CLS");		
		printf("%d�β���(AC:%d WA:%d)\n",tot,AC,WA);
		printf("������...\n-------------------------------------\n");
		system("datamaker.exe");
		system("CLS");
		printf("%d�β���(AC:%d WA:%d)\n",tot,AC,WA);
		printf("�������...\n-------------------------------------\n");
		system("std.exe");
		system("CLS");
		printf("%d�β���(AC:%d WA:%d)\n",tot,AC,WA);
		printf("ѡ�ֳ�������...\n-------------------------------------\n");
		system("xc.exe");
		system("CLS");
		printf("%d�β���(AC:%d WA:%d)\n",tot,AC,WA);
		printf("����ж�...\n-------------------------------------\n");
		if(system("fc x.out x.ans")){
			WA++;
			system("pause");
		}
		else{
			AC++;
		}
	}
	return 0;
}


