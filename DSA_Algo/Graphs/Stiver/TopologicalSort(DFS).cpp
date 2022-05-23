#include<bits/stdc++.h>
using namespace std;

void dfsTopo(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]){
	vis[node]=1;
	for(auto it : adj[node]){
		if(!vis[it]){
			dfsTopo(it, vis, st, adj);
		}
	}
	st.push(node);
	//cout<<st.top()<<" ";
}

vector<int> topoSort(int V, vector<int> adj[]){
	stack<int> st;
	vector<int> vis(V+1, 0);
	for(int i=1;i<=V;i++){
		if(vis[i]==0){
			dfsTopo(i, vis, st, adj);
		}
	}
	vector<int> topo;
	//cout<<st.size();
	while(!st.empty()){
		topo.push_back(st.top());
		//cout<<st.top()<<endl;
		st.pop();
	}
	return topo;
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
	}
	
	vector<int> ans = topoSort(V, adj);
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	
	return 0;
}
