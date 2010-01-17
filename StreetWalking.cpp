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
class StreetWalking {
public:
  long long minTime(int X, int Y, int walkTime, int sneakTime)
  {
    // all sneak
    long long ret = (long long)sneakTime * (long long)min(X, Y);
    if ((long long)abs(X-Y) % 2 == 0)
      ret += (long long)sneakTime * (long long)abs(X-Y);
    else
      ret += (long long)sneakTime * ((long long)abs(X-Y)-1) + (long long)walkTime;

    // sneak and walk
    ret = min(ret, (long long)sneakTime * (long long)min(X, Y) + (long long)walkTime * (long long)abs(X - Y));

    // all walk
    return min(ret, (long long)walkTime * (long long)(X + Y));
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
