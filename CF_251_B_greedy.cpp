//the IDE crashed when I nearly finished....sad......
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
vector<int>even, odd;
vector<int>ae[maxn], ao[maxn];
void init(int n, int m) {
	even.clear();
	odd.clear();
	for(int i=0; i<n ; i++)ae[i].clear();
	for(int i=0; i<m; i++)ao[i].clear();
}
void print(int n, int m) {
	for(int i=0 ; i<n ; i++) {
		printf("%d", ao[i].size());
		for(int j=0; j<ao[i].size(); j++) {
			printf(" %d", ao[i][j]);
		}
		puts("");
	}
	for(int i=0; i<m; i++) {
		printf("%d", ae[i].size());
		for(int j=0; j<ae[i].size(); j++) {
			printf(" %d", ae[i][j]);
		}
		puts("");
	}
}
int main() {
	int n, k, p;
	cin>>n>>k>>p;
	int v;
	for(int i=0; i<n; i++) {
		scanf("%d", &v);
		if(v&1)odd.push_back(v);
		else even.push_back(v);
	}
	int opt=0, osz=odd.size();
	int ept=0, esz=even.size();
	if(osz<k-p) {
		puts("NO");
	} else {
		for(; opt<k-p; opt++) {
			ao[opt].push_back(odd[opt]);
		}
		if((osz-opt)&1) {
			puts("NO");
		} else {
			for(; ept<esz && ept<p; ept++) {
				ae[ept].push_back(even[ept]);
			}
			if(ept<p) {
				int cnt=ept;
				for(; opt<osz && cnt<p; opt+=2, cnt++) {
					ae[cnt].push_back(odd[opt]);
					ae[cnt].push_back(odd[opt+1]);
				}
				if(cnt<p) {
					puts("NO");
				} else {
					for(; opt<osz; opt+=2) {
						ae[0].push_back(odd[opt]);
						ae[0].push_back(odd[opt+1]);
					}
					puts("YES");
					print(k-p, p);
				}
			} else {
				for(; opt<osz; opt+=2) {
					ae[0].push_back(odd[opt]);
					ae[0].push_back(odd[opt+1]);
				}
				for(; ept<esz; ept++) {
					ae[0].push_back(even[ept]);
				}
				puts("YES");
				print(k-p, p);
			}
		}
	}

}
