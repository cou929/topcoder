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
class MinimalDifference {
public:
  int getDigitSum(int n) {
    int ret = 0;

    while (n > 0) {
      ret += n%10;
      n /= 10;
    }

    return ret;
  }

  int findNumber(int A, int B, int C) {
    int digit_sum_c = getDigitSum(C);
    int mini = INT_MAX;
    int ret = 0;
    
    for (int i=A; i<=B; i++) {
      int ds = getDigitSum(i);
      if (mini > abs(ds-digit_sum_c)) {
        mini = abs(ds-digit_sum_c);
        ret = i;
      }
      if (mini == 0)
        break;
    }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
