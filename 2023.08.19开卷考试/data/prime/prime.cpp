#include <cstdio>
#include <map>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <time.h> 
#include <random>

using namespace std;
long long Max_n = pow(2,31);
long long a,b,p;
long long power(long long a, long long b, long long c) {//快速幂
    if(b==0)
        return 1%c;
    long long ans=1,t=a;
    while(b>0) {
       if(b%2==1) ans=ans*t%c;
       b/=2; t=t*t%c;
    }
    return ans;
}
long long bsgs(long long a,long long b,long long p) {//bsgs
	map<long long,long long> hash; hash.clear();//建立一个Hash表
	b%=p;
	long long t=sqrt(p)+1;
	for(register long long i=0;i<t;++i)
		hash[(long long)b*power(a,i,p)%p]=i;//将每个j对应的值插入Hash表
	a=power(a,t,p);
	if(!a) return b==0?1:-1;//特判
	for(register long long i=1;i<=t;++i) {//在Hash表中查找是否有i对应的j值
		long long val=power(a,i,p);
		int j=hash.find(val)==hash.end()?-1:hash[val];
		if(j>=0&&i*t-j>=0) return i*t-j;
	}
	return -1;//无解返回-1
}
bool isPrime(long long a) {
  if (a < 2) return 0;
  for (long long i = 2; i * i <= a; ++i)
    if (a % i == 0) return 0;
  return 1;
}
signed main() {
	std::mt19937 rng(time(0));
	for (int i = 1; i <= 10;i++)
	{
		string infile_name = std::to_string(i)+".in";
		string outfile_name = std::to_string(i)+".out";
		ofstream infile(infile_name);
		ofstream outfile(outfile_name);
		
		
		//scanf("%lld%lld%lld",&p,&a,&b);
		p = rng()%Max_n+2;
		while(!isPrime(p))
		{
			p = rng()%Max_n+2;
		}
		a = rng()%Max_n+2;
		b = rng()%Max_n+2;
		infile<<p<<' '<<a<<' '<<b<<endl;
		long long ans=bsgs(a,b,p);
		if(ans==-1) outfile<<"no solution"<<endl;
		else outfile<<ans<<endl;
		cout<<ans<<endl;
	}
	return 0;
}
