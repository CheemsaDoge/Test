#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int MAXN=1e6+1145;
#define lch a*2
#define rch a*2+1
#define mid ((l+r)/2)
struct T{
	struct part{
		int l,r;
		int val,maxn;
		int tag;
	}rt[MAXN*4];
	int value[MAXN*4];
	void build(int a,int l,int r)
	{
		rt[a].l=l;
		rt[a].r=r;
		if(l==r)
		{
			rt[a].val=value[l];
			rt[a].maxn=value[l];
			return ;
		}
		build(lch,l,mid);
		build(rch,mid+1,r);
		rt[a].val=rt[lch].val+rt[rch].val;
	}
	void add(int a,int l,int r,int val)
	{
		if(rt[a].l>l&&rt[a].r<r)
			rt[a].tag+=val;
	}
};
int main()
{
	
	
}
