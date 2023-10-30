/*code by Cheemsadoge*/
#include <bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &x) {x=0;T w=1,ch=getchar();while(!isdigit(ch)&&ch!='-')ch=getchar();if(ch=='-')w=-1,ch=getchar();while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();x=x*w;}//fast input
const int MAXN=1e5+1145;const int INF=2147483647ll;//2^31-1
#define db double
#define ll long long
/*---------------------------------pre------------------------------------*/
db h,x[8],r[8],x0;
db EPS=1e-4;
struct Segment{
	db rp,lp;
	int num;
}seg[8];

void get_seg(db add)
{
	for(int i=1;i<=7;i++)
	{
		db len=sqrt((r[i]+add)*(r[i]+add)-h*h);
		seg[i].rp=len+x[i];seg[i].lp=x[i]-len;seg[i].num=i;
	}
}
bool cmp_for_seg(Segment a,Segment b)
{
	return a.rp>b.rp;
}
bool pd()
{
	sort(seg+1,seg+8,cmp_for_seg);
	db left=x0;
	for(int i=1;i<=8;i++)
	{
		if(seg[i].rp<left) return false;
		left=min(left,seg[i].lp);
	}
	return true;
}

db binary_search(db l,db r)
{
	#define mid (l+r)/2
	if(abs(r-l)<EPS) return mid;
	get_seg(mid);
	if(pd()) return binary_search(l,mid);
	else return binary_search(mid,r); 
}

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	freopen("equation.in", "r", stdin);
	freopen("equation.out", "w", stdout);
	scanf("%lf%lf",&h,&x0);
	for(int i=1;i<=8;i++) scanf("%lf%lf",&x[i],&r[i]);
	printf("%.2lf",binary_search(0,x0));
	return 0;
}
