#include <bits/stdc++.h>
using namespace std;
long long d[100010], n ,m;

long long lowbit( long long x ){
	return x & (-x);
}

//树状数组的lowbit 运算，可以百度一下

void add(long long x,long long v){
	while(x<=n){
		d[x]+=v; //给每一个数的前缀和加上v;
		x+=lowbit(x); //下一个祖先
	}
}
                
long long res; //定义在函数内部容易超时
                
//询问a的前缀和
long long ask(long long a){
	res=0;
	while(a!=0){
		res+=d[a];
		a-=lowbit(a);
	}
	return res;
}
                
long long h,x,y;
                
int main(){
	freopen("easy.in","r",stdin); 
	freopen("easy.out","w",stdout); 
	cin>>n>>m;
	while(m--){
		cin>>h;
		if(h==1) {
			cin>>x>>y;

  			//后面两步是重点！！！
			add(x,1); 
			add(y+1,1);
  
		}
		if(h==2){
			cin>>x;
			cout<<ask(x)%2<<endl;
		}	
	}
}
