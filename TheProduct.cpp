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
#include <limits.h>
using namespace std;
class TheProduct {
public:
  long long maxProduct(vector <int> numbers, int K, int maxDist) {
    long long dpmax[11][51];
    long long dpmin[11][51];
    
    for (int i=0; i<11; i++)
      for (int j=0; j<51; j++)
        {
          dpmax[i][j] = LLONG_MIN;
          dpmin[i][j] = LLONG_MAX;
        }

    for (int i=0; i<numbers.size(); i++)
      dpmax[1][i] = dpmin[1][i] = numbers[i];

    for (int k=2; k<=K; k++)
      for (int i=0; i<numbers.size(); i++)
        for (int j=0; j<i; j++)
          if (i - j <= maxDist && dpmax[k-1][i] != LLONG_MIN)
            {
              dpmax[k][j] = max(dpmax[k][j], max(numbers[j] * dpmax[k-1][i], numbers[j] * dpmin[k-1][i]));
              dpmin[k][j] = min(dpmin[k][j], min(numbers[j] * dpmax[k-1][i], numbers[j] * dpmin[k-1][i]));
            }

    long long ret = LLONG_MIN;
    for (int i=0; i<numbers.size(); i++)
      ret = max(ret, dpmax[K][i]);

    return ret;

  }

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
