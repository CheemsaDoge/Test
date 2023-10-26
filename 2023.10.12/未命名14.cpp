#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int a[16];
void print(){
    for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<a[i*4+j]<<" ";
            }
            cout<<endl;
        }
    cout<<"-------------------------------------"<<endl;
}
void shengcheng(){
    int b=rand()%16;
    int c;
    if(a[b]==0){
        int c=rand()%3;
        if(c==0)a[b]=4;
        else a[b]=2;
    }
    else{
        bool flag=false;
        for(int j=0;j<16;j++){
            if(a[j]==0){
                flag=true;
                int c=rand()%3;
                if(c==0)a[j]=4;
                else a[j]=2;
                break;
            }
        }
        if(flag==false){
            cout<<"you lose!"<<endl;
            exit(0);
        }
    }
}
void moved(int fsnd){
    if(fsnd==1){
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(a[i*4+j]==0){
                    for(int k=j;k>0;k--){
                        a[i*4+k]=a[i*4+k-1];
                    }
                    a[i*4]=0;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(a[i*4+j-1]==a[i*4+j]&&a[i*4+j]!=0){
                    a[i*4+j]*=2;
                    a[i*4+j-1]=0;
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=3;j>0;j--){
                if(a[i*4+j]==0){
                    for(int k=j;k>0;k--){
                        a[i*4+k]=a[i*4+k-1];
                    }
                    a[i*4]=0;
                    break;
                }
            }
        }
    }
    if(fsnd==2){
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(a[i*4+j]==0){
                    for(int k=j;k<3;k++){
                        a[i*4+k]=a[i*4+k+1];
                    }
                    a[i*4+3]=0;
                    break;
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(a[i*4+j+1]==a[i*4+j]&&a[i*4+j]!=0){
                    a[i*4+j]*=2;
                    a[i*4+j+1]=0;
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                if(a[i*4+j]==0){
                    for(int k=j;k<3;k++){
                        a[i*4+k]=a[i*4+k+1];
                    }
                    a[i*4+3]=0;
                    break;
                }
            }
        }
    }
}
int main(){
    srand(114514);
    int i=67;
    while(i--){
        shengcheng();
        print();
        int x;
        cin>>x;
        moved(x);
    }
    return 0;
}
