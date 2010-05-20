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
#include <numeric>
using namespace std;
class TheMoviesLevelOneDivTwo {
public:
  int find(int n, int m, vector <int> row, vector <int> seat) {
    int ret = 0;
    int i, j, k;

    for (i=1; i<=n; i++) {
      vector <int> cols;
      cols.push_back(0);
      cols.push_back(m + 1);
      for (j=0; j<row.size(); j++)
        if (row[j] == i)
          cols.push_back(seat[j]);
      sort(cols.begin(), cols.end());

      for (j=0; j<cols.size()-1; j++)
        ret += max(0, cols[j+1] - cols[j] - 2);
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
