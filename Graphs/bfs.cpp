 /*
  *@author = benihime
  */

#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false)
#define ll long long int
using namespace std;
void bfs(vector<ll> g[], bool vst[], ll s){
	list<ll> q;
	q.push_back(s);
	while(!q.empty()){
		ll u = q.front();
		q.pop_front();
		vst[u] = true;
		cout<<u<<" ";
		for(ll v : g[u]){
			if(!vst[v]){
				q.push_back(v);
				vst[v] = true;
			}
		}
	}
}
int main()
{
	fast_io;
	ll v,e;
	cin>>v>>e;
	vector<ll> g[v+1];
	for(ll i = 0; i < e; i++){
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
	}
	bool vst[v+1];
	memset(vst, false, v+1);
	for(ll i = 0; i < v; i++){
		if(!vst[i]){
			bfs(g, vst, i);
		}
	}
	return 0;
}