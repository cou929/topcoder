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
class NumericalPerfectionLevel {
public:
  int getLevel(long long N)
  {
    int ret = 0;
    int factor = 0;
    long long m = N;

    for (int i=2; i*i<=m; i++)
      {
	while (m % i == 0)
	  {
	    m /= i;
	    factor++;
	  }
      }

    if (m != 1)
      factor++;

    while (factor / 4 > 0)
      {
	ret++;
	factor /= 4;
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
