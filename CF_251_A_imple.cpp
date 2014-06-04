//easy one...had something wrong with my computer at first, badluck..
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
using namespace std;
int main(){
	int d, n;
	while(cin>>n>>d){
		int sum=0;
		for(int i=0; i<n; i++){
			int v;cin>>v;
			sum+=v;
		}
		int rest=(n-1)*10;
		if(rest+sum>d){
			puts("-1");
		}else{
			int t=d-rest-sum;
			int ans=rest/5+t/5;
			cout<<ans<<endl;
		}
	}
}
