/*********This code shows wrong output refer once again**********


#include<bits/stdc++.h>
using namespace std;

void DfsTopo(int node, vector<int> vis, stack<int> &st, vector<pair<int,int>> adj[]){
	vis[node]=1;
	for(auto it : adj[node]){
		if(!vis[it.first]){
			DfsTopo(it.first, vis, st, adj);
		}
	}
	st.push(node);
}

void shortestPath(int src, int V, vector<pair<int,int>> adj[]){
	vector<int> vis(V,0);
	stack<int> st;
	for(int i=0;i<V;i++){
		if(!vis[i]){
			DfsTopo(i, vis, st, adj);
		}
	}
	
	int dis[V];
	for(int i=0;i<V;i++){
		dis[i]=INT_MAX;
	}
	
	dis[src]=0;
	
	while(!st.empty()){
		int node  = st.top();
		st.pop();
		if(dis[node] != INT_MAX){
			for(auto it : adj[node]){
				if(dis[node]+it.second < dis[it.first]){
					dis[it.first] = dis[node] + it.second; 
				}
			}
		}
	}
	for(int i=0;i<V;i++){
		//cout<<"0 to "<<i<<" : "<<dis[i]<<endl;
		cout<<dis[i]<<endl;
	} 
}

int main(){
	int V,E;
	cout<<"Enter num of Nodes(V) and Edges(E): ";
	cin>>V>>E;
	
	vector<pair<int,int>> adj[V];
	
	for(int i=1;i<=E;i++){
		int u,v,w;
		cout<<"Enter nodes having edge in between them and its weight: ";
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
	}
	
	shortestPath(0, V, adj);
	
	return 0;
}
