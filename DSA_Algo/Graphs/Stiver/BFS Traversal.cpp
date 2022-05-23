#include<bits/stdc++.h>
using namespace std;

vector<int> bfsOfGraph(int V, vector<int> adjlist[]){
	
	vector<int> bfs;  //stores values to print;
	vector<int> visited(V+1,0);  //initialize all nodes as 0(means not visited)
	//we are V+1 size, graph value starts fron 1 then 0th position will be dummy, count from 1 bcouz our nodes start from 1.
	for(int i=1;i<=V;i++){   //this loop is not called everytime it is called only for components.
		if(!visited[i]){             //OR if(vis[i]==0)
			queue<int> q;
			q.push(i);
			visited[i] = 1;
			
			while(!q.empty()){  //OR q.empty==false   for line 15 while loop it takes O(V) complexity, as while loop running depends on edges
				int node = q.front();  // in adjlist[node] at line 22, line 22 for loop takes O(E) complexity. Now, at line 9 for loop is there but mostly
				                       //running depends on edges don't consider that loop bcouz we use that only when there are 2 graps components(i.e. there is one graph
				//cout<<node<<endl;        but they are not connected. On internet for loop step(lin 9) is mainly vomited. see commented code
				q.pop();                    //so TC: O(V+E)
				bfs.push_back(node);
				
				for(auto it : adjlist[node]){  //if graph is like first node is connected to 
					if(!visited[it]){
						q.push(it);
						visited[it] = 1;
					}
				}
			}
		}
	}
	return bfs;
	
	
	
	             //OR if(vis[i]==0)
			/*queue<int> q;
			q.push(1);
			visited[1] = 1;
			
			while(!q.empty()){  
				int node = q.front();   
				q.pop();
				bfs.push_back(node);
				
				for(auto it : adjlist[node]){  //if graph is like first node is connected to 
					if(!visited[it]){
						q.push(it);
						visited[it] = 1;
					}
				}
			}
	
	
	return bfs;*/
}

int main(){
	int V,E;
	cout<<"Enter num of nodes(V) and edges(E)"<<endl;
	cin>>V>>E;
	
	vector<int> adjlist[V+1];
	
	for(int i=1;i<=E;i++){
		
		int u,v;
		cout<<"Enter nodes having edge in between them"<<endl;
		cin>>u>>v;
		adjlist[u].push_back(v);  //if 1 and 2 has edge then 2 to 1 will also have edge
		adjlist[v].push_back(u);  //edge betn 2 to 1, this can happen only for undirected graph
	}

	vector<int> ans = bfsOfGraph(V,adjlist);
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
