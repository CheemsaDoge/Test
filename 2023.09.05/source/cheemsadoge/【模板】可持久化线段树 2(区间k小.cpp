/*code by ��ǹ����������İ�����������һ��*/
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
int rt[MAXN],a[MAXN],b[MAXN];
struct _PART{	int id,lch,rch,val;
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
		tr[_id].val=0;
		return ;
	}
	int mid=(l+r)>>1;
	Newtree(l,mid,tr[_id].lch);
	Newtree(mid+1,r,tr[_id].rch);
	tr[_id].val=tr[tr[_id].lch].val+tr[tr[_id].rch].val;
}
void pushup(int _id)
{
	tr[_id].val=tr[tr[_id].lch].val+tr[tr[_id].rch].val;	
}
void update(int l,int r,int &_id,int x)
{
	_id=clone(_id);
	tr[_id].val++;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(x>mid) update(mid+1,r,tr[_id].rch,x);
		if(x<=mid) update(l,mid,tr[_id].lch,x);
	}
}
int query(int u_id,int v_id,int l,int r,int x)
{
	if(l>=r) return l;
	int nlch=tr[tr[v_id].lch].val-tr[tr[u_id].lch].val;
	int mid=(l+r)>>1;
	if(nlch>=x) return query(tr[u_id].lch,tr[v_id].lch,l,mid,x);
	else return query(tr[u_id].rch,tr[v_id].rch,mid+1,r,x-nlch);
	return 0;
}
int l,r,k;
int val;
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)
		read(a[i]),b[i]=a[i];
	sort(b+1,b+1+n);
	val=unique(b+1,b+1+n)-b-1;
	Newtree(1,val,rt[0]);
	for(int i=1;i<=n;i++)
	{
		int t=lower_bound(b+1,b+1+val,a[i])-b;
		rt[i]=rt[i-1];
		update(1,val,rt[i],t);
	}
	for(int i=1;i<=m;i++)
	{
		read(l);read(r);read(k);
		write(b[query(rt[l-1],rt[r],1,val,k)]),pc;
	}
	return 0;
}
