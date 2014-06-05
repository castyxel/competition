//组合数学＋数论比较对，首先用插空法确定总分配数，然后如果某方案能整体被x整除，方案数相当于 p/x, f的方案数，不便于枚举，但可用mobius反演进行化简计算，mobius的作用是，利用一个已知函数，求未知函数的值，在这里，设总方案数为permu(p, f), 所求方案f(p, f)，则有permu(p, f) = sigma( if(d|p) f(d, f))
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
const int ed = 100000;
typedef long long ll;
const ll mod = 1000000000+7;
vector<int>divs[maxn];
ll fac[maxn], mobi[maxn], invs[maxn];
bool isprime[maxn];
int prime[maxn], pcnt;
ll quickpow(ll a, ll b){
	ll ret = 1;
	while(b){
		if(b&1) ret = (ret*a) % mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return ret;
}
void preHandle(){
	fac[0]=1;
	invs[0]=1;
	for(ll i=1; i<=ed; i++){
		fac[i] = i*fac[i-1];
		fac[i] %= mod;
		invs[i] = quickpow(fac[i], mod-2);
	}
	for(int i=1; i<=ed; i++){
		for(int j=i; j<=ed; j+=i){
			divs[j].push_back(i);
		}
	}
	memset(isprime, true, sizeof(isprime));
	pcnt=0;
	for(int i=0; i<=ed; i++) mobi[i]=0;
	mobi[1] = 1;
	for(int i=2; i<=ed; i++){
		if(isprime[i]){
			prime[pcnt++]=i;
			for(int j=i; j<=ed; j+=i){
				isprime[j] = false;
			}
			mobi[i] = -1;
		}
		ll m=1;
		for(int j=0; j<pcnt; j++){
			if(i%prime[j]==0){
				m *= -1;
				int k=0, ki=i;
				while(ki%prime[j]==0){
					k++;
					ki /= prime[j];
					if(k>1){
						m=0;
						break;
					}
				}
				if(m==0) break;
			}
		}
		mobi[i] = m;
	}
}
ll comb(ll n, ll m){
	if(n<m) return 0;
	if(n==m) return 1;
	if(m==0) return 1;
	ll inv = invs[n-m] * invs[m];
	inv %= mod;
	return (fac[n]*inv)%mod;
}
ll getans(ll p, ll f){
	ll ans = 0;
	int sz = divs[p].size();
	for(int i=0; i<sz; i++){
		ll d = divs[p][i];
		//   cout<<d<<endl;
		//   cout<<"mobi[d]="<<mobi[d]<<" comb("<<p/d-1<<", "<<f-1<<")="<<comb(p/d-1, f-1)<<endl;
		ans = ans + ((mobi[d]*comb(p/d-1, f-1)) % mod);
		ans %= mod;
		ans = (ans + mod) % mod;
	}
	return ans;
}
void test(){
	for(int i=1; i<5000; i++){
		cout<<i<<" "<<mobi[i]<<endl;
	}
}
int main(){
	int q;
	cin>>q;
	ll p, f;
	preHandle();
	//  cout<<divs[98280].size()<<endl;
	//test();
	while(q--){
		cin>>p>>f;
		ll ans = getans(p, f);
		cout<<ans<<endl;
	}
}

