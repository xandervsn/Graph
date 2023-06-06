/* Xander Siruno-Nebel
   C++/Data Structures, Galbraith
   6/6/23
   Graph; representation of an adjacency matrix in C++
 */

#include <iostream>
#include <cstring>
using namespace std;

class graph {
public:
  int adjList[21][21];
  int vertices;
  int** workable(){
    cout << "workable:" << endl;
    int ** newList = new int*[vertices - 1];
    for(int x = 0; x < vertices - 1; x++){
      newList[x] = new int[vertices - 1];
      for(int y = 0; y < vertices - 1; y++){
	newList[x][y] = adjList[x+1][y+1];
	cout << newList[x][y] << " ";
      }
      cout << endl;
    }
    return newList;
  }
  
  void dijkstra(int** G,int n,int startnode) {
    int max = vertices - 1;
    int cost[max][max],distance[max],pred[max];
    int visited[max],count,mindistance,nextnode,i,j;
    for(i = 0; i < n; i++){
      for(j = 0; j < n; j++){
	if(G[i][j] == 0){
	  cost[i][j] = 999;
	}else
	  cost[i][j] = G[i][j];
      }
    }
    for(i = 0; i < n; i++){
      distance[i] = cost[startnode][i];
      pred[i] = startnode;
      visited[i] = 0;
    }
    distance[startnode] = 0;
    visited[startnode] = 1;
    count=1;
    while(count < n - 1){
      mindistance = 999;
      for(i = 0; i < n; i++){
	if(distance[i] < mindistance && !visited[i]){
	  mindistance = distance[i];
	  nextnode = i;
	}
      }
      visited[nextnode] = 1;
      for(i = 0; i < n; i++){
	if(!visited[i]){
	  if(mindistance + cost[nextnode][i] < distance[i]) {
	    distance[i] = mindistance + cost[nextnode][i];
	    pred[i] = nextnode;
	  }
	}
      }
      count++;
    }
    for(i = 0; i < n; i++){
      if(i != startnode){
	cout << "\nDistance of node" << i << " = " << distance[i];
	cout << "\nPath = " << i;
	j = i;
	do{
	j = pred[j];
	  cout << " <- " << j;
	}while(j != startnode);
      }
    }
  }
  
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
    for(int x = 0; x <= vertices; x++){
      for(int y = 0; y <= vertices; y++){
	if(x > index - 1 || y > index - 1){
	  if(x == y){
	    adjList[x][y] = 0;
	  }else if(x <= 1){
	    adjList[x][y] = adjList[x][y+1];
	  }else if(y <= 1){
	    adjList[x][y] = adjList[x+1][y];
	  }else{
	    adjList[x][y] = adjList[x+1][y+1];
	  }
	}
      }
    }
    adjList[0][0] = 32;
    vertices--;
  }

  void addEdge(char a, char b, int weight){
    for(int x = 0; x <= vertices; x++){
      for(int y = 0; y <= vertices; y++){
	if((adjList[x][0] == a && adjList[y][0] == b)){
	  adjList[x][y] = weight;
	}
      }
    }
  }

  void removeEdge(char a, char b){
    for(int x = 0; x <= vertices; x++){
      for(int y = 0; y <= vertices; y++){
        if((adjList[x][0] == a && adjList[y][0] == b)){
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

  /*  
  while(true){
    char input[10];
    char label;
    char label2;
    int weight = 0;
    cout << "Input command (vAdd, vDlt, eAdd, eDlt, print, quit, path)" << endl;
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
  */
  
  
  obj.addVertex('A');
  obj.addVertex('B');
  obj.addVertex('C');
  obj.addVertex('D');
  obj.addVertex('E');

  obj.addEdge('A', 'B', 1);
  obj.addEdge('D', 'A', 3);
  obj.addEdge('E', 'A', 10);
  obj.addEdge('B', 'C', 5);
  obj.addEdge('C', 'D', 2);
  obj.addEdge('E', 'C', 1);
  obj.addEdge('E', 'D', 6);

  /*
  obj.addEdge('A', 'B', 6);
  obj.addEdge('A', 'D', 1);
  obj.addEdge('D', 'B', 2);
  obj.addEdge('D', 'E', 1);
  obj.addEdge('B', 'E', 2);
  obj.addEdge('C', 'B', 5);
  obj.addEdge('C', 'E', 5);
  
  obj.addEdge('A', 'B', 1);
  obj.addEdge('A', 'C', 2);
  obj.addEdge('A', 'D', 3);
  obj.addEdge('A', 'E', 4);
  obj.addEdge('B', 'C', 1);
  obj.addEdge('B', 'D', 2);
  obj.addEdge('B', 'E', 3);
  obj.addEdge('C', 'D', 1);
  obj.addEdge('C', 'E', 2);
  obj.addEdge('D', 'E', 1);
  */

  obj.print();

  obj.dijkstra(obj.workable(), 4, 0);
  
  cout << endl;
    
  
  return 0;
}
