#include<bits/stdc++.h>
using namespace std;

vector<int> topoSort(int V, vector<int> adj[]){
	queue<int> q;
	vector<int> indegree(V+1, 0);
	for(int i=1;i<=V;i++){  //i=1 bcouz our nodes starts from 1 for this code example
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	
	for(int i=1;i<=V;i++){
		if(indegree[i]==0) q.push(i);
	}
	
	vector<int> topo;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		topo.push_back(node);
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}
	return topo;
}



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
	
	vector<int> ans = topoSort(V, adj);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
