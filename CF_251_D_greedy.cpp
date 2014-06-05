//easy one....当时怎么就没想出来呢，自己画上下两线，上线表小，下线表大，把值在中间分布，分析一下，就知道是贪心可做了……
//据说三分可做，暂没想好。。。
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <map>
using namespace std;
const int maxn = 100005;
bool cmp(int aa, int bb){
	return aa>bb;
}
typedef long long ll;
ll a[maxn], b[maxn];
int main(){
	int n, m;
	while(cin>>n>>m){
		for(int i=0; i<n; i++)cin>>a[i];
		for(int i=0; i<m; i++)cin>>b[i];
		sort(a, a+n);
		sort(b, b+m, cmp);
		ll ans=0;
		int apt=0, bpt=0;
		while(apt<n && bpt<m){
			if(a[apt]>=b[bpt])break;
			ans += b[bpt]-a[apt];
			apt++, bpt++;
		}
		cout<<ans<<endl;
	}
}

