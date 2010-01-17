#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <map>

using namespace std;

class ColumnDiagramPerimeter {
public:
  int getPerimiter(vector <int> a)
  {
    int i;
    int ret = 0;

    ret = a.size() * 2;

    a.insert(a.begin(), 0);
    a.push_back(0);

    for (i=0; i<a.size()-1; i++) {
      ret += abs(a[i] - a[i+1]);
    }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
