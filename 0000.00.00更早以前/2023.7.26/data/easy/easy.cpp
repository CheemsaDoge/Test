#include <bits/stdc++.h>
using namespace std;
long long d[100010], n ,m;

long long lowbit( long long x ){
	return x & (-x);
}

//��״�����lowbit ���㣬���԰ٶ�һ��

void add(long long x,long long v){
	while(x<=n){
		d[x]+=v; //��ÿһ������ǰ׺�ͼ���v;
		x+=lowbit(x); //��һ������
	}
}
                
long long res; //�����ں����ڲ����׳�ʱ
                
//ѯ��a��ǰ׺��
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

  			//�����������ص㣡����
			add(x,1); 
			add(y+1,1);
  
		}
		if(h==2){
			cin>>x;
			cout<<ask(x)%2<<endl;
		}	
	}
}
