#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=2e5+5;
int un,n,m,a[N],ANS[N],ma[N],b[N],bn,num[N],st[N],cn,clear[N];
//�����Ľ�������Ĵ����ж���Ŷ������
struct que{
	int l,r,i;
	inline bool operator < (const que &nt) const {
		return (b[l]^b[nt.l])?b[l]<b[nt.l]:r<nt.r; //�Ȱ���߽����ڿ��ţ���ͬʱ�ٰ��ұ߽���
	}
}q[N];

inline int max(const int &x,const int &y){
	return x>y?x:y;
}

int calc(int l,int r){ //����ɨһ��
	int last[N],res=0;
	for(int i=l;i<=r;i++) last[a[i]]=0; //��¼ÿ����������ֵ�λ��
	for(int i=l;i<=r;i++) if(!last[a[i]]) last[a[i]]=i; else res=max(res,i-last[a[i]]);
	return res;
}

signed main(){
	read(n);
	int len=sqrt(n); //�鳤
	for(int i=1;i<=n;i++) num[i]=read(a[i]),b[i]=(i-1)/len+1; //b��¼ÿ���±������ĸ����е�
	bn=b[n]; //����
	sort(num+1,num+1+n);
	un=unique(num+1,num+1+n)-num-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(num+1,num+1+un,a[i])-num; //��������ɢ����
	read(m);
	for(int i=1;i<=m;i++){
		read(q[i].l);read(q[i].r);
		q[i].i=i;
	}
	sort(q+1,q+1+m); //ѯ������
	for(int i=1,j=1;j<=bn;j++){ //iö��ѯ��,jö��ѯ�ʵ���߽����ڿ�
		int br=min(n,j*len),l=br+1,r=l-1,ans=0; //br�ǵ�ǰ����ұ߽�
		cn=0; //��ռ�¼�����ָ��
		for(;b[q[i].l]==j;i++){ //ö�ٵ�ǰ���ڵ�ѯ��
			if(b[q[i].r]==j){ //������ұ߽綼��ͬһ�����ھͱ�����
				ANS[q[i].i]=calc(q[i].l,q[i].r);
				continue;
			}
			while(r<q[i].r){
				r++;
				ma[a[r]]=r; //�����ֵ�λ��
				if(!st[a[r]]) st[a[r]]=r,clear[++cn]=a[r]; //st��������ֵ�λ�ã�clear�ǳ��ֹ������֣�����������������ֵ�λ��
				ans=max(ans,r-st[a[r]]); //���2
			}
			int tp=ans; //�ȱ���һ�£���Ϊ������Ĺ��ײ��ᱻˢ�£���������Ļ�
			while(l>q[i].l){
				l--;
				if(ma[a[l]]) ans=max(ans,ma[a[l]]-l);
				else ma[a[l]]=l; //�����ֵ�λ�ÿ�������������
			}
			ANS[q[i].i]=ans;
			while(l<=br){
				if(ma[a[l]]==l) ma[a[l]]=0; //ȥ��������Ĺ���
				l++;
			}
			ans=tp; //ȥ����ǰ������Ĺ���
		}
		for(int i=1;i<=cn;i++) ma[clear[i]]=st[clear[i]]=0; //���ݼ�¼�������ÿ��������λ�õĸ�����Ϣ
	}
	for(int i=1;i<=m;i++) write(ANS[i]),puts("");
}
