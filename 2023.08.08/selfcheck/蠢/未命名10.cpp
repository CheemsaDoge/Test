#include<bits/stdc++.h>
using namespace std;
inline int read(){int f=1,x=0;char ch;do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0'||ch>'9');do{x=x*10+ch-'0';ch=getchar();}while(ch>='0'&&ch<='9');return f*x;}
int a[5];
const int p=2;
int C(int n,int m){
    if(m>n)return 0;
    return 1;
}
int Lucas(int n,int m){
    if(!m) return 1;
    return C(n%p,m%p)*Lucas(n/p,m/p)%p;
}
int main() {
	vector<int>a;
	while(1)
	{
		int b;
		cin>>b;
		a.push_back(b);
		printf("%d\n",a.size());
	}
}
