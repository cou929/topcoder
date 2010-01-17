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
class BouncingBalls {
public:
  double expectedBounces(vector <int> x, int T) {
    double ret = 0;
    sort(x.begin(), x.end());

    for (long long i=0; i<(1 << x.size()); i++) {
      long long tmp = i;
      for (int j=0; j<x.size(); j++) {
        if ((tmp >> j) & 1) {
          for (int k=j+1; k<x.size(); k++) {
            if (!((tmp >> k) & 1)) {
              //              cout << tmp << endl;
              if ((double)(x[k] - x[j]) / 2.0 <= (double)T) {
                //                cout << x[k] << " - " << x[j] << " / 2 = " << (x[k] - x[j]) / 2 << endl;
                ret++;
              }
            }
          }
        }
      }
    }

    ret /= (1 << x.size());
    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
