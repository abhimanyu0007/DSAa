#include<bits/stdc++.h>
using namespace std;

bool checkLoop(int s,vector<int> adj[],int V){
	vector<int> vis(V+1,0);
	queue<pair<int,int>> q;
	q.push({s,-1});
	while(q.empty()==false){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		
		for(auto it : adj[node]){
			if(vis[it] == 0){
				vis[it]=1;
				q.push({it,node});
			}
			else if(parent!=it){
				return true;
			}
		}
	}
	return false;
}

int main(){
	int V,E;
	cout<<"Enter no. of nodes and edges: ";
	cin>>V>>E;
	
	vector<int> adj[V+1];
	for(int i=1;i<=E;i++){
		int v,u;
		cout<<"Enter node having edge in between them: ";
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//cout<<checkLoop(1,adj,V);
	int ans = checkLoop(1,adj,V);
	
	if(ans==true) cout<<"Cycle Present";
	else cout<<"No Cycle Present";	
	
	return 0;
}
