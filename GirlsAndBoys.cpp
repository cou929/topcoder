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
class GirlsAndBoys {
public:
  int sortThem(string row) {
    int ret = 0;
    int i, n = row.size();

    int counter = 0;
    string tmp = row;
    while (1) {
      int localc = 0;

      for (i=0; i<n-1; i++)
        if (tmp[i] == 'B' && tmp[i+1] == 'G') {
          char c = tmp[i];
          tmp [i] = tmp[i+1];
          tmp[i+1] = c;
          localc++;
        }

      if (localc == 0) break;
      counter += localc;
    }

    ret = counter;

    tmp = row;
    counter = 0;
    while (1) {
      int localc = 0;

      for (i=0; i<n-1; i++)
        if (tmp[i] == 'G' && tmp[i+1] == 'B') {
          char c = tmp[i];
          tmp [i] = tmp[i+1];
          tmp[i+1] = c;
          localc++;
        }

      if (localc == 0) break;
      counter += localc;
    }

    ret = min(ret, counter);

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
