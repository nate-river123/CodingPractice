 /*
  *@author = benihime
  */

#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false)
#define ll long long int
using namespace std;
bool cycleDfs(vector<ll> g[], bool vst[], ll s, ll p){
	vst[s] = true;
	for(ll v : g[s]){
		if(vst[v] && v != p){
			return true;
		}
		else if(!vst[v]){
			return cycleDfs(g, vst, v, s);
		}
	}
	return false;
}
int main()
{
	fast_io;
	ll v,e;cin>>v>>e;
	vector<ll> g[v+1];
	for(ll i = 0; i < e; i++){
		ll a,b;
		cin>>a>>b;
		g[a].push_back(b);
		g[b].push_back(a); 
	}
	bool vst[v+1];
	memset(vst, false, v+1);
	bool result = false;
	for(ll i = 0; i < v; i++){
		if(!vst[i]){
			result = cycleDfs(g, vst, i, -1);
		}
	}
	if(result)cout<<"Cycle detected"<<endl;
	else cout<<"Cycle not detected"<<endl;
	return 0;
}