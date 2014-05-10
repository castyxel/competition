#include <cstdio>
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
#include<cstring>
using namespace std;
const int MAXN = 4005;
struct node{
	int x, y, id;
	bool operator <(const struct node &b) const{
		return id>b.id;
	}
};
char g[MAXN][MAXN];
typedef pair<int, int> P;
int dir[4][2]={0, 1, 0, -1, 1, 0, -1, 0};
int n, m;
int max(int a, int b){
	if( a>b)return a;
	return b;
}
bool inedge(node a){
	if(0<=a.x && a.x<n && 0<=a.y && a.y <m)
		return true;
	return false;
}
int ans;
bool vis[MAXN][MAXN];
void bfs(){
	memset(vis, false, sizeof(vis));
	priority_queue<node, vector<node> >qb;
	node a;
	a.x=0, a.y=0, a.id=1;
	vis[0][0]=true;
	qb.push(a);
	while(!qb.empty()){
		node fst = qb.top();qb.pop();
		for(int i=0; i<4; i++){
			node cur;
			cur.x = fst.x + dir[i][0];
			cur.y = fst.y + dir[i][1];
			if(!inedge(cur))continue;
			if('.' == g[cur.x][cur.y])continue;
			if(vis[cur.x][cur.y])continue;
			vis[cur.x][cur.y]=true;
			
			if(g[fst.x][fst.y] != g[cur.x][cur.y]){
				cur.id = fst.id+1;
				ans = max(ans, cur.id);
			}else{
				cur.id = fst.id;
			}
			qb.push(cur);
		}
	}
}
int main(){
	int ncase;
	cin>>ncase;
	while(ncase--){
		scanf("%d%d", &n, &m);
		for(int i=0; i<n; i++)
			scanf("%s", g[i]);
		ans = 1;
		bfs();
		printf("%d\n", ans);
	}
}
