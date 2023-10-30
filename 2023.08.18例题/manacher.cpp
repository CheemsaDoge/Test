/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
template<typename T> inline void write(T x){static char q[65];int cnt=0;if(x<0)putchar('-'),x=-x;q[++cnt]=char(x%10),x/=10;while(x)q[++cnt]=char(x%10),x/=10;while(cnt)putchar(q[cnt--]+'0');}
const int MAXN=3e7+1e6+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pn puts("no")
/*---------------------------------pre------------------------------------*/


char in[MAXN],a[MAXN<<1];
int hw[MAXN],n;
void change()
{
	a[0]=a[1]='#';
	for(int i=0;i<n;i++)
	{
		a[i*2+2]=in[i];
		a[i*2+3]='#';
	}
	n=n*2+2;
	a[n]=0;
}

void manacher()
{
	int mid,maxr=0;
	for(int i=1;i<n;i++)
	{
		if(i<maxr) hw[i]=min(hw[(mid<<1)-i],hw[mid]+mid-i);
		else hw[i]=1;
		while(a[hw[i]+i]==a[i-hw[i]]) hw[i]++;
		if(hw[i]+i>maxr) {
			maxr=hw[i]+i;
			mid=i;
		}
	}
}
int main() {
//	freopen("ans.ans","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
    scanf("%s",in);
    n=strlen(in);
    change();
    manacher();
    int ans=1;
    for(int i=0;i<n;i++)
        ans=max(ans,hw[i]);
    write(ans-1);
    return 0; 
}
