 /*
  * @author = benihime
  * Why we can't use undirected cycle detection algo?
  *	https://stackoverflow.com/questions/10972028/finding-a-cycle-in-an-undirected-graph-vs-finding-one-in-a-directed-graph
  */

#include <bits/stdc++.h>
#define fast_io ios::sync_with_stdio(false)
#define ll long long int
using namespace std;
bool cycleDfsDirected(vector<ll> g[], bool vst[], ll s, unordered_set<ll> &rec){
	vst[s] = true;
	rec.insert(s);
	for(ll v : g[s]){
		if(vst[v] && rec.find(v)!=rec.end()){
			return true;
		}
		else if(!vst[v]){
			return cycleDfsDirected(g, vst, v, rec);
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
		ll a,b;cin>>a>>b;
		g[a].push_back(b); //Directed graph
	}
	bool vst[v+1];
	memset(vst, false, v+1);
	bool result = false;
	for(ll i = 0; i < v; i++){
		if(!vst[i]){
			unordered_set<ll> rec; 
			result = cycleDfsDirected(g, vst, i, rec);
		}
	}
	if(result)cout<<"Cycle detected"<<endl;
	else cout<<"Cycle not detected"<<endl;
	return 0;
}