#include<bits/stdc++.h>
using namespace std;

bool detectLoop(int node, int parent, vector<int> adj[], vector<int> vis){
	vis[node]=1;
	for(auto it : adj[node]){
		if(vis[it] == 0){  //this if checks it node is visted or not
			if(detectLoop(it, node, adj, vis)==true){
				return true;
			}	
		}
		else if(it!=parent){  //this statement runs if node is not visited
			return true;
		}
	}
	return false;
}

bool checkLoop(int V, vector<int> adj[]){
	vector<int> vis(V+1,0);
	
	if(detectLoop(1, -1, adj, vis)==true) return true;
	else return false;
	
}

int main(){
	int V,E;
	cout<<"Enter no. of nodes(V) and edged(E): ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=1;i<=E;i++){
		int u, v;
		cout<<"Enter nodes having edge in between them: "<<endl;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	int ans = checkLoop(V, adj); //be conscious pass V(no. of nodes), adj(adjacency list)
	
	if(ans == true) cout<<"Cycle Present";
	else cout<<"No Cycle Present";
	
	return 0;
}
