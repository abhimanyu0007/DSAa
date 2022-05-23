#include<bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<int> adj[], int color[]){
	queue<int> q;
	q.push(node);
	color[node] = 1;
	while(q.empty()){
		int vertex = q.front();
		q.pop();
		for(auto it : adj[vertex]){
			if(color[it]==-1){
				color[it] = 1 - color[vertex];
				q.push(it);
			}
			else if(color[it] == color[vertex]){
				return false;
			}
		}
	}
	return true;
}

bool checkBipartite(int V, vector<int> adj[]){
	int color[V+1];
	memset(color, -1, sizeof color);
	if(bfs(1, adj, color)==false){
		return false;
	}
	else{
		return true;
	}
	
}


int main(){
	int V, E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	for(int i=1;i<=E;i++){
		cout<<"Enter nodes having edge in betn them: "<<endl;
		int u, v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	if(checkBipartite(V, adj)==false) cout<<"Not Bipartite Graph";
	else cout<<"Yes Bipartite Graph";
	return 0;
}
