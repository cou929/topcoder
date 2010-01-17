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
class CutSticks {
public:
  double maxKth(vector <int> sticks, int C, int K) {
    double ret = 0;
    double left = 0, right = 1e09, mid = 0;

    for (int i=0; i<1000; i++) {
      mid = (right + left) / 2;

      int number_of_large_stick = 0, number_of_cut = 0;
      int c = C;
      for (int j=0; j<sticks.size(); j++) {
        if (sticks[j] < mid) continue;
        number_of_cut = (int)(max(sticks[j] / mid - 1.0, 0.0));
        number_of_cut = min(number_of_cut, c);
        c -= number_of_cut;
        number_of_large_stick += number_of_cut + 1;
      }

      if (number_of_large_stick >= K)
        left = mid;
      else
        right = mid;
    }

    ret = mid;

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
