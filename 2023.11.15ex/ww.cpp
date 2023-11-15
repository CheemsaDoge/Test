/*** 
 * @Author: CheemsaDoge
 * @Date: 2023-11-15 15:56:14
 * @LastEditors: CheemsaDoge
 * @LastEditTime: 2023-11-15 15:56:19
 * @FilePath: \TEST\2023.11.15ex\ww.cpp
 * @Forgive me.
 * @Copyright (c) 2023 by CheemsaDoge, All Rights Reserved. 
 */
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i,sa=1,sb=1,lena,lenb;
	char a[7],b[7];
	scanf("%s",a);
    scanf("%s",b);
	lena=strlen(a);
	lenb=strlen(b);
	for(i=0;i<lena;++i) sa=sa*int(a[i]-64);
	for(i=0;i<lenb;++i) sb=sb*int(b[i]-64);
	if(sa%47==sb%47) cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0; 
} 