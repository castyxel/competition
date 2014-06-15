//implementation
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
using namespace std;
const int maxn = 1005;
char stra[maxn], strb[maxn];
int lena, lenb;
bool isthesame(){
	if(lena != lenb) return false;
	for(int i=0; i<lenb; i++){
		if(stra[i]!=strb[i]) return false;
	}
	return true;
}
int backnum(){
	int ret=0;
	int len=min(lena, lenb);
	if(lenb>lena) ret += lenb-lena;

	int pt=0;
	for(; pt<len; pt++){
		if(stra[pt]!=strb[pt]) break;
	}
	ret += len - pt;
	return ret;
}
int getnew(){
	int ret=1;
	return ret+1+lena;
}
int main(){
	int ncase;
	cin>>ncase;
	while(ncase--){
		scanf("%s", stra);
		lena = strlen(stra);
		scanf("%s", strb);
		lenb = strlen(strb);

		if(isthesame()){
			puts("*");
			continue;
		}

		int backn=backnum(), getn=getnew();
		if(lenb-backn==lena && backn+1<=getn){
			for(int i=0; i<backn; i++)putchar('<');
			puts("*");
			continue;
		}
		int mores = lena - (lenb-backn);
		if(mores+backn+1<=getn){
			for(int i=0; i<backn; i++)putchar('<');
			for(int i=lenb-backn; i<lena; i++)
				putchar(stra[i]);
			puts("*");
			continue;
		}
		putchar('*');
		printf("%s", stra);
		puts("*");
	}
}

