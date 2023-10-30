#include<bits/stdc++.h>
using namespace std;
int n;
const int P=131;
char s[2000005];
unsigned long long Hash[2000005];
unsigned long long bin[2000005];
int flag=0;
unsigned long long hash_left;
unsigned long long hash_right;
int pos=-1;
unsigned long long ans=0;
int main() {
	n=read();
	scanf("%s",s+1);
	if(n%2==0) {
		printf("NOT POSSIBLE");
		return 0;
	}
	bin[0]=1;
	for(register int i=1; i<=n; i++) {
		Hash[i]=Hash[i-1]*P+s[i];
		bin[i]=bin[i-1]*P;
	}
	int mid=(n+1)/2;
	for(register int i=1; i<=n; i++) {
		hash_left=0;
		hash_right=0;
		if(i<mid) {
			hash_left=Hash[i-1]*bin[mid-i]+Hash[mid]-Hash[i]*bin[mid-i];
			hash_right=Hash[n]-Hash[mid]*bin[n-mid];
		}
		if(i==mid) {
			hash_left=Hash[i-1];
			hash_right=Hash[n]-Hash[mid]*bin[n-mid];
		}
		if(i>mid) {
			hash_left=Hash[mid-1];
			hash_right=(Hash[i-1]-Hash[mid-1]*bin[i-mid])*bin[n-i]+Hash[n]-Hash[i]*bin[n-i];
		}
		if(hash_left==hash_right) {
			if(flag==0)flag++,pos=i,ans=hash_left;
			else if(ans!=hash_left) {
				flag++;
				break;
			}

		}
	}
	if(flag>1)printf("NOT UNIQUE");
	if(flag==0)printf("NOT POSSIBLE");
	if(flag==1) {
		if(pos<mid)
			for(register int i=mid+1; i<=n; i++)printf("%c",s[i]);
		if(pos>mid)
			for(register int i=1; i<mid; i++)printf("%c",s[i]);
		if(pos==mid)
			for(register int i=1; i<mid; i++)printf("%c",s[i]);
	}
	return 0;
}
