 /*
  *@author = benihime
  */

#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false)
#define ll long long int
using namespace std;
void dfs(vector<int> g[], bool vst[], int s){
	cout<<s<<" ";
	vst[s] = true;
	for(ll v : g[s]){
		if(!vst[v]){
			dfs(g, vst, v);
		}
	}
}
int main()
{
	fast_io;
	int v,e;cin>>v>>e;
	vector<int> g[v+1];
	for(int i = 0; i < e; i++){
		ll a,b;cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a);        /*  Uncomment for undirected graph  */
 	}
	bool vst[v+1];
	memset(vst, false, sizeof(vst));
	for(ll i = 0; i < v; i++){
		if(!vst[i]){
			dfs(g, vst, i);
		}
	}
	return 0;
}