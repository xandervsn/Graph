#include <iostream>

using namespace std;

class vertex{
 public:
  vertext();
  ~vertex();
  char name;
  int index;
  int getEdge(int);
  int setEdge(int, int);
 private:
  int edges[];
};
