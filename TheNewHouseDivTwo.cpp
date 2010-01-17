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
class TheNewHouseDivTwo {
public:
  int count(vector <int> x, vector <int> y) {
    int ret = 0;

    for (int i=-100; i<=100; i++)
      for (int j=-100; j<=100; j++) {
        bool flg[4] = {false, false, false, false}; 
        for (int k=0; k<x.size(); k++) {
          if (x[k] == i && y[k] > j)
            flg[0] = true;
          if (x[k] == i && y[k] < j)
            flg[1] = true;
          if (x[k] > i && y[k] == j)
            flg[2] = true;
          if (x[k] < i && y[k] == j)
            flg[3] = true;
        }
        if (flg[0] && flg[1] && flg[2] && flg[3])
          ret++;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
