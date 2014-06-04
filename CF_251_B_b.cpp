//easy one...
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <map>
using namespace std;
const int maxn = 100005;
typedef long long ll;
ll s[maxn];
int main(){
	int n, x;
	while(cin>>n>>x){
		for(int i=0; i<n; i++){
			cin>>s[i];
		}
		sort(s, s+n);
		ll ans=0;
		ll pt=x;
		for(int i=0; i<n; i++, pt--){
			if(pt==0)pt=1;
			ans+=pt*s[i];
		}
		cout<<ans<<endl;
	}
}
