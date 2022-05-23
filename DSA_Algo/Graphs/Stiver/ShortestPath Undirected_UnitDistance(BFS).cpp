#include<bits/stdc++.h>
using namespace std;

void shortestPath(int V, vector<int> adj[], int src, int dest){
	int dis[V];
	
	for(int i=0;i<V;i++) dis[i]=INT_MAX;
	
	queue<int> q;
	dis[src]=0;
	q.push(src);
	
	while(!q.empty()){
		int node = q.front();
		q.pop();
		for(auto it : adj[node]){
			if(dis[node]+1 < dis[it]){
				dis[it] = dis[node]+1;
				q.push(it);
			}
		}
	}
	for(int i=0;i<V;i++){
		cout<<"0 to "<<i<<" : "<<dis[i]<<" ";
	} 
	//cout<<dis[dest];
	
	
}

int main(){
	int V, E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=0;i<E;i++){
		int u,v;
		cout<<"Enter nodes having edges in betn them: "<<endl;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int source = 0;  //as an example i have taken 0 & 6, you can instead ask that to user.
	int destination = 6;
	
	shortestPath(V, adj, source, destination);
	//cout<<ans;
	
	return 0;
}
