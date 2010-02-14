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
class LampsGrid {
public:
  int mostLit(vector <string> initial, int K) {
    int ret = 0;

    for (int i=0; i<initial.size(); i++) {
      int num = count(initial[i].begin(), initial[i].end(), '0');
      if (num <= K && (K - num) % 2 == 0)
        ret = max(ret, count(initial.begin(), initial.end(), initial[i]));
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
