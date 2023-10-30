/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXM=5e5+10;const int MAXN=5e5+10;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no solution")
/*---------------------------------pre------------------------------------*/


int WA,AC,tot;
int main()
{
	while(1)
	{
		tot++;
		system("CLS");		
		printf("%d次测试(AC:%d WA:%d)\n",tot,AC,WA);
		printf("造数据...\n-------------------------------------\n");
		system("datamaker.exe");
		system("CLS");
		printf("%d次测试(AC:%d WA:%d)\n",tot,AC,WA);
		printf("标程运行...\n-------------------------------------\n");
		system("std.exe");
		system("CLS");
		printf("%d次测试(AC:%d WA:%d)\n",tot,AC,WA);
		printf("选手程序运行...\n-------------------------------------\n");
		system("keywords.exe");
		system("CLS");
		printf("%d次测试(AC:%d WA:%d)\n",tot,AC,WA);
		printf("结果判断...\n-------------------------------------\n");
		if(system("fc keywords.out keywords.ans")){
			WA++;
			system("pause");
		}
		else{
			AC++;
		}
	}
}
