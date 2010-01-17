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
class AdditionCycles {
public:
  int cycleLength(int n)
  {
    int ret = 0;
    int cur = n;

    while (++ret)
      {
	int tmp = cur/10 + cur%10;
	cur = cur%10 * 10 + tmp%10;
	if (cur == n)
	  break;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
