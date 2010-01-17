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
class ContiguousCacheEasy {
public:
  int bytesRead(int n, int k, vector <int> addresses)
  {
    int base = 0;
    int ret = 0;

    for (int i=0; i<addresses.size(); i++)
      {
	if (base + (k-1) < addresses[i])
	  {
	    int oldbase = base;
	    base = min(addresses[i] - (k - 1), n - (k-1));
	    if (oldbase + (k-1) < base)
	      ret += k;
	    else
	      ret += (int)abs(base - oldbase);
	  }
	else if (addresses[i] < base)
	  {
	    int oldbase = base;
	    base = max(0, addresses[i]);
	    if (base + (k-1) < oldbase)
	      ret += k;
	    else
	      ret += (int)abs(base - oldbase);
	  }
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
