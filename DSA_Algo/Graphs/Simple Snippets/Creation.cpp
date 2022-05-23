#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int DestinationVertexID;
		int weight;
		
		Edge(){
			
		}
		
		Edge(int destVID, int w){
			DestinationVertexID = destVID;
			weight = w;
		}
		
		void setEdgeValues(int destVID, int w){
			DestinationVertexID = destVID;
			weight = w;
		}
		
		void setWeight(int w){
			weight = w;
		}
		
		int getDestinationVertexID(){
			return DestinationVertexID;
		}
		
		int getWeight(){
			return weight;
		}
};

class Vertex{
	public:
		int state_id;
		string state_name;
		
		list<Edge> edgeList; //**IMP** objects created in edge class will be stored in edgelist
		
		Vertex(){
			state_id = 0;
			state_name = "";
		}
		
		Vertex(int id, string sname){
			state_id = id;
			state_name = sname;
		}
		
		int getStateID(){
			return state_id;
		} 
		
		string getStateName(){
			return state_name;
		}
		
		void setID(int id){
			state_id = id;
		} 
		
		void setStateName(string sname){
			state_name = sname;
		}
		
		list<Edge> getEdgeList(){
			return edgeList;
		} 
};

class Graph{
	public:
		vector<Vertex> vertices;  //stores objects of type:-vertex
		
		//All graph operations will be coded here.
};

int main(){
	
	return 0;
}
