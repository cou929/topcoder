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
class BitwiseEquations {
public:
  long long kthPlusOrSolution(int x, int k)
  {
    long long ret = 0;
    int n = 0;

    while (x != 0 || k != 0)
      {
	if ((x & 1) == 0)
	  {
	    if ((k & 1) == 1)
	      ret += (long long)pow((double)2, n);
	    k = k >> 1;
	  }
	x = x >> 1;
	n++;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
