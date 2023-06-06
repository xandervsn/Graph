// Adjacency Matrix representation in C++

#include <iostream>
#include <cstring>
using namespace std;

class graph {
private:
  int adjList[21][21];
  int vertices;
public:
  graph(){
    vertices = 1;
    for(int x = 0; x < 20; x++){
      for(int y = 0; y < 20; y++){
	adjList[x][y] = 0;
      }
    }
    adjList[0][0] = 32;
  };
  
  void addVertex(int name){
    if(!adjList[0][0]){
      adjList[0][0] = name;
    }else{
      for(int x = 0; x <= vertices; x++){
	for(int y = 0; y <= vertices; y++){
	  if(!adjList[x][y]){
	    if(!x || !y){
	      adjList[x][y] = name;
	    }else{
	      adjList[x][y] = 0;
	    }
	  }
	}
      }
    }
    vertices++;
  }
  
  void removeVertex(char vertex){
    int index = 0;
    for(int i = 0; i <= vertices; i++){
      if(adjList[i][0] == vertex) index = i;
    }
    for(int x = index - 1; x <= vertices; x++){
      for(int y = index - 1; y <= vertices; y++){
	if(x == y){
	  adjList[x][y] = 0;
	}else if(x == 1 || x == 0){
	  adjList[x][y] = adjList[x][y+1];
	}else if(y == 1 || x == 0){
	  adjList[x][y] = adjList[x+1][y];
	}else{
	  adjList[x][y] = adjList[x+1][y+1];
	}
      }
    }
    adjList[0][0] = 32;
    vertices--;
  }

  void addEdge(char a, char b, int weight){
    for(int x = 0; x <= vertices; x++){
      for(int y = 0; y <= vertices; y++){
	if((adjList[x][0] == a && adjList[y][0] == b) || (adjList[x][0] == b && adjList[y][0] == a)){
	  adjList[x][y] = weight;
	}
      }
    }
  }

  void removeEdge(char a, char b){
    for(int x = 0; x <= vertices; x++){
      for(int y = 0; y <= vertices; y++){
        if((adjList[x][0] == a && adjList[y][0] == b) || (adjList[x][0] == b && adjList[y][0] == a)){
          adjList[x][y] = 0;
        }
      }
    }
  }

  void print(){
    for(int x = 0; x < vertices; x++){
      for(int y = 0; y < vertices; y++){
	if(!x || !y){
	  cout << (char)adjList[x][y] << " ";
	}else{
	  cout << adjList[x][y] << " ";
	}
      }
      cout << endl;
    }
  }
};

int main(){
  graph obj;

  
  while(true){
    char input[10];
    char label;
    char label2;
    int weight = 0;
    cout << "Input command (vAdd, vDlt, eAdd, eDlt, print, quit)" << endl;
    cin >> input;

    if(strcmp(input, "vAdd") == 0){
      cout << "Input label to add (1 char)" << endl;
      cin >> label;
      obj.addVertex(label);
    }else if(strcmp(input, "vDlt") == 0){
      cout << "Input label to delete (1 char)" << endl;
      cin >> label;
      obj.removeVertex(label);
    }else if(strcmp(input, "eAdd") == 0){
      cout << "Input first vertex:" << endl;
      cin >> label;
      cout << "Input second vertex:" << endl;
      cin >> label2;
      cout << "Input weight:" << endl;
      cin >> weight;
      obj.addEdge(label, label2, weight);
    }else if(strcmp(input, "eDlt") == 0){
      cout << "Input first vertex:" << endl;
      cin >> label;
      cout << "Input second vertex:" << endl;
      cin >> label2;
      obj.removeEdge(label, label2);
    }else if(strcmp(input, "print") == 0){
      obj.print();
    }else if(strcmp(input, "quit") == 0){
      break;
    }
  }
  return 0;
  
  
  /*
  obj.addVertex('c');
  obj.addVertex('b');
  obj.addVertex('t');

  obj.addEdge('c', 't', 1);
  obj.addEdge('b', 'c', 5);

  obj.print();

  cout << endl;
  */  
  
  return 0;
}
