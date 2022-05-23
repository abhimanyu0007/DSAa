#include<bits/stdc++.h>
using namespace std;

class loop{
	public:
		
		bool dfsCheck(int node, vector<int> adj[], int vis[], int dfsVis[]){
			vis[node]=1;
			dfsVis[node]=1;
			for(auto it : adj[node]){
				if(!vis[it]){
					if(dfsCheck(it, adj, vis, dfsVis)) return true;
				}
				else if(dfsVis[it]==1) return true;
			}
			dfsVis[node] = 0;
			return false;
		}
		
		bool checkCycle(int V, vector<int> adj[]){
			int vis[V+1], dfsVis[V+1];
			memset(vis, 0, sizeof vis);
			memset(dfsVis, 0, sizeof dfsVis);
			
			for(int i=1;i<=V;i++){
				if(!vis[i]){  //vis[i]==0
					if(dfsCheck(i, adj, vis, dfsVis)) return true;
				}
			}
			return false;
		}	
};

int main(){
	int V, E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=1;i<=E;i++){
		int u,v;
		cout<<"Enter nodes having edge in betn them: "<<endl;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	loop obj;
	if(obj.checkCycle(V, adj)) cout<<"Loop Present";
	else cout<<"No Loop Present";
	
	return 0;
}
