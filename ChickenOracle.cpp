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
class ChickenOracle {
public:
  bool check(int n, int eggCount, int lie, int lier) {
    bool ret = false;
    int ec = n - lie;
    int left = max(lier - (n - ec), 0);
    int right = min(ec, lier);
    int i, tmp;
    
    for (i=left; i<=right; i++) {
      tmp = ec - i + (lier - i);
      if (tmp == eggCount) {
        ret = true;
        break;
      }
    }
    
    return ret;
  }

  string theTruth(int n, int eggCount, int lieCount, int liarCount) {
    string ret;
    
    bool isEgg = check(n, eggCount, lieCount, liarCount);
    bool isChicken = check(n, n - eggCount, lieCount, liarCount);

    if (isEgg && isChicken)
      ret = "Ambiguous";
    else if (isEgg)
      ret = "The egg";
    else if (isChicken)
      ret = "The chicken";
    else
      ret = "The oracle is a lie";

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
