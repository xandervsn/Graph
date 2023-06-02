// Adjacency Matrix representation in C++

#include <iostream>
using namespace std;

class graph {
private:
  int adjList[20][20];
  int vertices;
public:
  graph(){
    vertices = 0;
  };
  
  void addVertex(int name){
    if(!adjList[0][0]){
      for(int x = 0; x < 20; x++){
	for(int y = 0; y < 20; y++){
	  adjList[x][y] = 0;
	}
      }
      adjList[0][0] = name;
      cout << name << endl;
    }else{
      for(int x = 0; x <= vertices; x++){
	for(int y = 0; y <= vertices; y++){
	  if(adjList[x][y] == 0){
	    adjList[x][y] = name;
	    cout << name << endl;
	  }
	}
      }
    }
    vertices++;
  }
  
  void removeVertex(){

  }

  void addEdge(int x, int y, int weight){
    adjList[x][y] = weight;
    adjList[y][x] = weight;
  }

  void removeEdge(int x, int y){
    adjList[x][y] = 0;
    adjList[y][x] = 0;
  }
  
  ~graph(){

  }
};

int main(){
  graph obj;
  obj.addVertex(5);
  obj.addVertex(6);
  obj.addVertex(1);
  
  return 0;
}
