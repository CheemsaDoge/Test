#include<bits/stdc++.h>
using namespace std;
int n,q,b[500005];
struct Node{
	int a,b,c,x;//a表示上次出现的位置，b表示上上次出现的位置，c表示上上上次出现的位置，x表示出现了几次
};
map<int,Node>m;//Node结构体用来存储每一个值的出现次数及前几次出现的位置
int lowbit(int x){return x&-x;}//lowbit函数，求正整数的二进制状态下的最低位的1的权值
struct node{
	int l,r,id,ans;
	bool operator<(const node &t)const{//重载node结构体的“<”运算符
		return id<t.id;
	}
}a[500005];//存储询问
struct BIT{//树状数组
	int c[500005];//c是树状数组的节点
	void Add(int x,int y){//将x这个位置的贡献加y
		while(x<=n){
			c[x]+=y;
			x+=lowbit(x);
		}
	}
	int Getsum(int x){//求x以前的前缀和
		int ans=0;
		while(x){
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
	int Getsum(int l,int r){//区间查询
		return Getsum(r)-Getsum(l-1);
	}
}T;
bool cmp(const node a,const node b){
	return a.r<b.r;
}
int main()
{
	freopen("nature.in","r",stdin);
	freopen("nature.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);//读入数据
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i].l,&a[i].r);//读入询问
		a[i].id=i;
	}
	sort(a+1,a+q+1,cmp);//将询问排序
	int cnt=1;
	for(int i=1;i<=q;i++){
		for(;cnt<=a[i].r;cnt++){//对每个询问的右端点以前的未处理的所有元素进行处理操作
			if(m.count(b[cnt])==1){
				if(m[b[cnt]].x==1){//已有1次出现，即这是第2次出现
					T.Add(m[b[cnt]].a,1);
					m[b[cnt]].x++;//标记次数
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
				}
				else if(m[b[cnt]].x==2){//已有2次出现，即这是第3次出现
					T.Add(m[b[cnt]].a,1);
					T.Add(m[b[cnt]].b,-2);
					m[b[cnt]].x++;//标记次数
					m[b[cnt]].c=m[b[cnt]].b;
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
				}
				else{//出现次数大于等于4
					T.Add(m[b[cnt]].a,1);
					T.Add(m[b[cnt]].b,-2);
					T.Add(m[b[cnt]].c,1);
					m[b[cnt]].c=m[b[cnt]].b;
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
					//因为出现的次数大于等于4了，所以不需要标记了。
				}
			}
			else{//以前还没出现过，即这是第1次出现
				m[b[cnt]].x++;//标记次数
				m[b[cnt]].a=cnt;
			}
		}
		a[i].ans=T.Getsum(a[i].l,a[i].r);
	}
	sort(a+1,a+q+1);
	for(int i=1;i<=q;i++){
		printf("%d\n",a[i].ans);
	}
	return 0;
}
