#include<bits/stdc++.h>
#define il inline
#define vd void
typedef long long ll;
il int gi(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int A[100010];
std::set<int> *q[1000010];
int main(){
	int n=gi(),m=gi(),res=0,opt,x,y;
	for(int i=1;i<=1000000;++i)q[i]=new std::set<int>;
	for(int i=1;i<=n;++i)A[i]=gi(),res+=A[i]!=A[i-1],q[A[i]]->insert(i);
	while(m--){
		opt=gi();
		if(opt==2)printf("%d\n",res);
		else{
			x=gi(),y=gi();if(x==y)continue;
			if(q[x]->size()>q[y]->size())std::swap(q[x],q[y]);
			for(auto i:*q[x])res-=q[y]->count(i-1)+q[y]->count(i+1);
			for(auto i:*q[x])q[y]->insert(i);
			q[x]->clear();
		}
	}
	return 0;
}
