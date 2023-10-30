#include <bits/stdc++.h>
int p[16] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53};
#define ul unsigned long long
ul n;
ul ans=1999999999999999999ll;
inline void dfs(ul depth, ul temp,ul num, ul up) {
	if(num>n||depth>=16)return;
	if(num==n&&ans>temp){
		ans=temp;
		return;
	}
	for(int i=1;i<=up;i++){
		if(temp*p[depth]>ans)
			break;
		temp*=p[depth];
		dfs(depth+1,temp,num*(i+1),i);
	}
}

int main(){
//	freopen("int.in","r",stdin);
//	freopen("int.out","w",stdout);
	scanf("%llu",&n);
	dfs(0,1,1,20);
	printf("%llu\n",ans);
	return 0;
}
