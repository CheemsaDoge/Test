/*code by 七枪六马五分钟四把三人两倒下一把*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=1e6+10;const int MAXN=1e6+10;const int INF=2147483647ll;//2^31-1
#define ll long long
#define pc putchar('\n')
#define pk putchar(' ')
#define pg putchar('/')
/*---------------------------------pre------------------------------------*/
int n,m;
int len;
int a[MAXN];
ll sum,cnt[MAXN];
struct query{
	int l,r,id,times;
	bool operator<(const query another) const {
		if (l / len == another.l / len) {
			if (r / len == another.r / len) return times < another.times;
			return r < another.r;
		}
		return l < another.l;
	}
}q[MAXM];
inline void add(int i) {if(!cnt[i]) sum++;cnt[i]++;}
inline void del(int i) {cnt[i]--;if(!cnt[i]) sum--;}
ll ans1[MAXN];
int mem[MAXM][5];//第几只 原本颜色 替换颜色 
char op[15];
int ct[MAXN];
int main()
{
	read(n);read(m);
	len=pow(n,(double)2/(double)3);
	for(int i=1;i<=n;i++) read(a[i]),ct[i]=a[i];
	int t1=0,t2=0;
	for(int i=1;i<=m;i++){
		scanf("%s",op);
		if(op[0]=='Q')			
			read(q[++t2].l),read(q[t2].r),q[t2].id=t2,q[t2].times=t1;
		else 
		{
			read(mem[t1][1]);
			mem[t1][2]=ct[mem[t1][1]];
			read(mem[t1][3]);
			ct[mem[t1][1]]=mem[t1][3];
			t1++;
		}
	}
	sort(q+1,q+t2+1);
	for(int i=1,l=1,r=0,lst=0;i<=t2;i++)
	{
		while(lst>q[i].times)
		{
			lst--;
			if(mem[lst][1]>=l&&mem[lst][1]<=r) del(mem[lst][3]),add(mem[lst][2]);
			a[mem[lst][1]]=mem[lst][2];
		}
		while(lst<q[i].times)
		{
			if(mem[lst][1]>=l&&mem[lst][1]<=r) del(mem[lst][2]),add(mem[lst][3]);
			a[mem[lst][1]]=mem[lst][3];
			lst++;
		}
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(l<q[i].l) del(a[l++]);
		while(r>q[i].r) del(a[r--]);
		ans1[q[i].id]=sum;
	}
	for(int i=1;i<=t2;i++) write(ans1[i]),pc;
}
