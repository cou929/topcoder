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
class DifferentStrings {
public:
  int minimize(string A, string B)
  {
    int ret = 1000000;

    for (int i=0; i<=B.size() - A.size(); i++)
      {
	int len = 0;
	for (int j=0; j<A.size(); j++)
	  {
	    if (A[j] != B[i+j])
	      len++;
	  }
	ret = min(len, ret);
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
