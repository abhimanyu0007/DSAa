#include<bits/stdc++.h>
using namespace std;

bool bipartiteDfs(int node, vector<int> adj[], int color[]){
	if(color[node]==-1){
		color[node] = 1;
	} 
	for(auto it : adj[node]){
		if(color[it]==-1){
			color[it] = 1- color[node];  //this assigns opposite value for one of the adjacent node.
			if(bipartiteDfs(it, adj, color)== false){
				return false;
			}
		}
		else if(color[it]== color[node]){
			return false;
		}
	}
	return true;
}

bool checkBipartite(int V, vector<int> adj[]){
	int color[V+1];
	
	memset(color, -1, sizeof color);
	/*for(int i=1;i<=V;i++){
		if(color[i]==-1){
			color[i]=1;
			if(bipartiteDfs(1, adj, color)  == false) return false;
		}
	}
	return true;*/
	if(bipartiteDfs(1, adj, color)  == true) return true;
	else return false;
}

int main(){
	int V,E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=1;i<=E;i++){
		cout<<"Enter nodes having edge in betn them: "<<endl;
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(checkBipartite(V, adj)==true){ //or if(checkBipartite(v, adj)){....}
		cout<<"Yes";
	}
	else{
		cout<<"No";
	}
	
	return 0;
}
