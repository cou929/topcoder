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
class BestView {
public:
  int numberOfBuildings(vector <int> heights) {
    int ret = 0;

    for (int i=0; i<heights.size(); i++) {
      int counter = 0;
      for (int j=0; j<heights.size(); j++) if (i != j) {
          int left = min(i, j), right = max(i, j);
          double ratio = (double)(heights[left] - heights[right]) / (double)(left - right);
          bool visible = true;
          for (int k=left+1; k<right; k++)
            if (heights[k] >= heights[left] + ratio * (k - left)) {
              visible = false;
              break;
            }
          if (visible) counter++;
        }
      ret = max(ret, counter);
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
