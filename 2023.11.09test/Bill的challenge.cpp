/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-09 08:51:39
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-09 08:54:10
 * @FilePath: \TEST\2023.11.09test\Bill的challenge.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;
const int mod=1000003;
const int MAXN=1.5e5+1145;
int f[100][200000],g[100][50];
char s[40][100];
int T,n,m;
int main(){
	scanf("%d",&T);
	while(T--){
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)scanf("%s",s[i]);
		int len=strlen(s[0]);
		for(int i=0;i<len;i++){//枚举位数
			for(int j=0;j<26;j++){//枚举字符
				for(int k=0;k<n;k++){//枚举行数
					if(s[k][i]=='?' || s[k][i]==j+'a')g[i][j]|=(1<<k);//位数为i时j字符的匹配情况
				}
			}
		}
		int lim=(1<<n);
		f[0][lim-1]=1;
		for(int i=0;i<len;i++){//枚举位数
			for(int j=0;j<lim;j++){//枚举状态
				if(f[i][j])//剪枝
					for(int k=0;k<26;k++){//枚举字符
						f[i+1][j&g[i][k]]=(f[i+1][j&g[i][k]]+f[i][j])%mod;
					}
			}
		}
		int ans=0;
		for(int i=0;i<lim;i++){//枚举状态
			int tot=0;
			for(int j=0;j<n;j++){
				if(i & (1<<j))tot++;
			}
			if(tot==m)ans=(ans+f[len][i])%mod;
		}
		printf("%d\n",ans);
		
	}
}