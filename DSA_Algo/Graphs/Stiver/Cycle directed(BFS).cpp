#include<bits/stdc++.h>
using namespace std;

bool detectCycle(int V, vector<int> adj[]){
	queue<int> q;
	vector<int> indegree(V+1,0);
	
	for(int i=1;i<=V;i++){
		for(auto it : adj[i]){
			indegree[it]++;
		}
	}
	
	for(int i=1;i<=V;i++){
		if(indegree[i]==0) q.push(i);
	}
	
	int count=0;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		count++;
		for(auto it : adj[node]){
			indegree[it]--;
			if(indegree[it]==0) q.push(it);
		}
	}
	if(count==V) return false;
	return true;
}

int main(){
	int V, E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	
	for(int i=1;i<=E;i++){
		int u,v;
		cout<<"Enter nodes having edges in betn them: "<<endl;
		cin>>u>>v;
		adj[u].push_back(v);
	}
	
	if(!detectCycle(V, adj)) cout<<"No Cycle Present";
	else cout<<"Cycle Present";
	
	return 0;
}
