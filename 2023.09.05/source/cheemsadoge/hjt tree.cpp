/*code by 七枪六马五分钟四把三人两倒下一把*/
#include<bits/stdc++.h>
using namespace std;
template<typename T> inline void read(T &_x) {_x=0;T _w=1,_ch=getchar();while(!isdigit(_ch)&&_ch!='-')_ch=getchar();if(_ch=='-')_w=-1,_ch=getchar();while(isdigit(_ch))_x=(_x<<3)+(_x<<1)+(_ch^'0'),_ch=getchar();_x=_x*_w;}//fast input
template<typename T> inline void write(T _x){static char _q[65];int _cnt=0;if(_x<0)putchar('-'),_x=-_x;_q[++_cnt]=char(_x%10),_x/=10;while(_x)_q[++_cnt]=char(_x%10),_x/=10;while(_cnt)putchar(_q[_cnt--]+'0');}
const int MAXM=2e5+1145;const int MAXN=2e6+1145;const int INF=2147483647ll;//2^31-1
#define pc putchar('\n')
#define pk putchar(' ')
int mod=19921228;
/*---------------------------------pre------------------------------------*/
int n,m;
int rt[MAXN],a[MAXN];
struct _PART{
	int id,lch,rch,val;
}tr[MAXN*20];
int totr;
int clone(int Pre)
{
	tr[++totr]=tr[Pre];
	tr[totr].id=totr;
	return totr;
}
void Newtree(int l,int r,int &_id)
{
	_id=++totr;
	if(l==r)
	{
		tr[_id].val=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	Newtree(l,mid,tr[_id].lch);
	Newtree(mid+1,r,tr[_id].rch);
}
void update(int l,int r,int &_id,int x,int v)
{
	_id=clone(_id);
	if(l==r){
		tr[_id].val=v;
		return ;
	}
	int mid=(l+r)>>1;
	if(x>mid) update(mid+1,r,tr[_id].rch,x,v);
	if(x<=mid) update(l,mid,tr[_id].lch,x,v);
}
int query(int _id,int l,int r,int x)
{
	if(l==r) return tr[_id].val;
	int mid=(l+r)>>1;
	if(x>mid) return query(tr[_id].rch,mid+1,r,x);
	if(x<=mid) return query(tr[_id].lch,l,mid,x);
	return -1;
}
int v,opt,loc,value;
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(a[i]);
	Newtree(1,n,rt[0]);
	for(int i=1;i<=m;i++)
	{
		read(v),read(opt),read(loc);
		rt[i]=rt[v];
		if(opt==1){
			read(value);
			update(1,n,rt[i],loc,value);
		}
		else write(query(rt[i],1,n,loc)),pc;
	}
	return 0;
}
