/**
  *@filename:��Ҫ62
  *@author: pursuit
  *@csdn:unique_pursuit
  *@email: 2825841950@qq.com
  *@created: 2021-05-12 19:56
**/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 100000 + 5;
const int mod = 1e9+7;

int l,r;
int f[11][11];//f[i][j]��ʾiλ�������λΪj�ķ�������
//��ô��������������з���������f[i][j]���״̬�����Ǹ�����������ת�Ƶ�f[i-1][k]��������k!=4,j!=4.
//����jk!=62.
void init(){
    for(int i=0;i<10;i++)f[1][i]=1;
    //�ų�4�������
    f[1][4]=0;
    for(int i=2;i<11;i++){
        for(int j=0;j<10;j++){
            if(j==4)continue;
            for(int k=0;k<10;k++){
                if((j==6&&k==2)||k==4)continue;
                f[i][j]+=f[i-1][k];
            }
        }
    }
}
int dp(int n){
    if(!n)return 1;
    vector<int> a;//�洢�ָ�λ����
    int ans=0,last=0;//last������һλ��ֵ��
    while(n)a.push_back(n%10),n/=10;
    for(int i=a.size()-1;i>=0;i--){
        int x=a[i];
        for(int j=0;j<x;j++){
            //����߷�֧��������Ҫ�жϡ�
            if(j==4||(j==2&&last==6))continue;
            ans+=f[i+1][j];
        }
        if(x==4||(last==6&&x==2))break;
        last=x;
        if(!i)ans++;
    }
    return ans;
}
void solve(){
}
int main(){
	freopen("No.in","r",stdin);
	freopen("No.out","w",stdout);
    init();
    while(cin>>l>>r&&(l||r)){
        cout<<dp(r)-dp(l-1)<<endl;
        solve();
    }
    return 0;
}

