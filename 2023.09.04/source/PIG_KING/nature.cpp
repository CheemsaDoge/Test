#include<bits/stdc++.h>
using namespace std;
int n,q,b[500005];
struct Node{
	int a,b,c,x;//a��ʾ�ϴγ��ֵ�λ�ã�b��ʾ���ϴγ��ֵ�λ�ã�c��ʾ�����ϴγ��ֵ�λ�ã�x��ʾ�����˼���
};
map<int,Node>m;//Node�ṹ�������洢ÿһ��ֵ�ĳ��ִ�����ǰ���γ��ֵ�λ��
int lowbit(int x){return x&-x;}//lowbit���������������Ķ�����״̬�µ����λ��1��Ȩֵ
struct node{
	int l,r,id,ans;
	bool operator<(const node &t)const{//����node�ṹ��ġ�<�������
		return id<t.id;
	}
}a[500005];//�洢ѯ��
struct BIT{//��״����
	int c[500005];//c����״����Ľڵ�
	void Add(int x,int y){//��x���λ�õĹ��׼�y
		while(x<=n){
			c[x]+=y;
			x+=lowbit(x);
		}
	}
	int Getsum(int x){//��x��ǰ��ǰ׺��
		int ans=0;
		while(x){
			ans+=c[x];
			x-=lowbit(x);
		}
		return ans;
	}
	int Getsum(int l,int r){//�����ѯ
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
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);//��������
	for(int i=1;i<=q;i++){
		scanf("%d%d",&a[i].l,&a[i].r);//����ѯ��
		a[i].id=i;
	}
	sort(a+1,a+q+1,cmp);//��ѯ������
	int cnt=1;
	for(int i=1;i<=q;i++){
		for(;cnt<=a[i].r;cnt++){//��ÿ��ѯ�ʵ��Ҷ˵���ǰ��δ���������Ԫ�ؽ��д������
			if(m.count(b[cnt])==1){
				if(m[b[cnt]].x==1){//����1�γ��֣������ǵ�2�γ���
					T.Add(m[b[cnt]].a,1);
					m[b[cnt]].x++;//��Ǵ���
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
				}
				else if(m[b[cnt]].x==2){//����2�γ��֣������ǵ�3�γ���
					T.Add(m[b[cnt]].a,1);
					T.Add(m[b[cnt]].b,-2);
					m[b[cnt]].x++;//��Ǵ���
					m[b[cnt]].c=m[b[cnt]].b;
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
				}
				else{//���ִ������ڵ���4
					T.Add(m[b[cnt]].a,1);
					T.Add(m[b[cnt]].b,-2);
					T.Add(m[b[cnt]].c,1);
					m[b[cnt]].c=m[b[cnt]].b;
					m[b[cnt]].b=m[b[cnt]].a;
					m[b[cnt]].a=cnt;
					//��Ϊ���ֵĴ������ڵ���4�ˣ����Բ���Ҫ����ˡ�
				}
			}
			else{//��ǰ��û���ֹ��������ǵ�1�γ���
				m[b[cnt]].x++;//��Ǵ���
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
