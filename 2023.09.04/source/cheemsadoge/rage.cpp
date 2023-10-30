/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=2e5+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
/*---------------------------------pre------------------------------------*/
int n,m,len;
struct query{
	int l,r,id;
}q[MAXN];
int a[MAXN],b[MAXN];
bool query_cmp(query _a,query _b)
{
	return (b[_a.l]^b[_b.l])?b[_a.l]<b[_b.l]:_a.r<_b.r;
}
struct TmpIN{
	int _x,_id;
}tmpin[MAXN];
bool TmpIN_cmp(TmpIN _a,TmpIN _b) {return _a._x<_b._x;}
int st[MAXN],ma[MAXN],ANS[MAXM],clear[MAXN],cn,bn;
inline void LSH()
{
	int _lst=0,_totr=0;
	sort(tmpin+1,tmpin+1+n,TmpIN_cmp);
	for(int i=1;i<=n;i++)
	{
		_totr+=tmpin[i]._x==_lst?0:1;
		a[tmpin[i]._id]=_totr;
		_lst=tmpin[i]._x;
	}
}
int calc(int l,int r){
	int last[MAXN],res=0;
	for(int i=l;i<=r;i++) last[a[i]]=0;
	for(int i=l;i<=r;i++) if(!last[a[i]]) last[a[i]]=i; else res=max(res,i-last[a[i]]);
	return res;
}
inline void Datain()
{
	read(n);
	len=int(sqrt(n));
	for(int i=1;i<=n;i++) read(tmpin[i]._x),tmpin[i]._id=i,b[i]=(i-1)/len+1;
	LSH();
	bn=b[n];
	read(m);
	for(int i=1;i<=m;i++) read(q[i].l),read(q[i].r),q[i].id=i;
	sort(q+1,q+1+m,query_cmp);
}

inline int max(const int &x,const int &y){
	return x>y?x:y;
}
inline void chijiudemoduinie()
{
	for(int i=1,j=b[q[1].l];j<=bn;j++)
	{
		int br=min(n,len*j);int l=br+1,r=l-1,ans=0;
		cn=0;
		for(;b[q[i].l]==j;i++)
		{
			if(b[q[i].l]==b[q[i].r])
			{
				ANS[q[i].id]=calc(q[i].l,q[i].r);
				continue;
			}
			while(r<q[i].r) {
				r++;
				if(!st[a[r]]) st[a[r]]=r,clear[++cn]=a[r];
				ma[a[r]]=r;
				ans=max(ans,r-st[a[r]]);
			}
			int tmp=ans;
			while(l>q[i].l)
			{
				l--;
				if(!ma[a[l]]) ma[a[l]]=l;
				else ans=max(ans,ma[a[l]]-l);
			}
			ANS[q[i].id]=ans;
			while(l<=br)
			{
				if(ma[a[l]]==l) ma[a[l]]=0;
				l++;
			}
			ans=tmp;
		}
		for(int z=1;z<=cn;z++) ma[clear[z]]=st[clear[z]]=0;
	}
}
int main()
{
	freopen("rage.in","r",stdin);
	freopen("rage.out","w",stdout);
	Datain();
	chijiudemoduinie();
	for(int i=1;i<=m;i++)
		write(ANS[i]),pc;
	return 0;
}
