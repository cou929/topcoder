#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
using namespace std;
class CellRemoval {
public:
  int ret;
  vector <int> parent;
  int deletedCell;

  int r(int pos) {
    if (pos == -1) {
      ret++;
      return 0;
    } else if (pos == deletedCell) {
      return 0;
    }

    r(parent[pos]);
    return 0;
  }

  int cellsLeft(vector <int> _parent, int _deletedCell) {
    ret = 0;
    parent = _parent;
    deletedCell = _deletedCell;
    int leafs[parent.size()];
    memset(leafs, 0, sizeof(leafs));

    for (int i=0; i<parent.size(); i++)
      if (parent[i] != -1)
        leafs[parent[i]]++;

    for (int i=0; i<parent.size(); i++)
      if (leafs[i] == 0)
        r(i);

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
