#include<bits/stdc++.h>
using namespace std;

class graph{
	private:
		void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &storeDfs){
			storeDfs.push_back(node);
			vis[node]= 1;
			for(auto it : adj[node]){
				if(vis[it]==0){
					dfs(it, vis, adj, storeDfs);
				}
			}
		}
	
	public:
		vector<int> dfsOfGraph(int V, vector<int> adj[]){
			vector<int> storeDfs;
			vector<int> visited(V+1,0);
			/*for(int i=1;i<=V;i++){   use this code when multiple disconnected graphs are there and commet line 25
				if(visited[i]==0){
					dfs(i, visited, adj, storeDfs);
				}
			}*/
			dfs(1, visited, adj, storeDfs);
			return storeDfs;
		}
};

int main(){
	int V,E;
	cout<<"Enter num of Nodes(V) and Edges(E): ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=1;i<=E;i++){
		int u,v;
		cout<<"Enter nodes having edge in between them: ";
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	graph obj;
	
	vector<int> ans = obj.dfsOfGraph(V, adj);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
