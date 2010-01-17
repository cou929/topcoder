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
class FunnyFence {
public:
  int getLength(string s)
  {
    int ret = 0;
    for (int i=0; i<s.size(); i++)
      {
	bool preIsHifun = false;;
	if (s[i] == '-')
	  preIsHifun = true;

	int j = i + 1;
	int len = 1;

	while ((preIsHifun && s[j] == '|') || (!preIsHifun && s[j] == '-'))
	  {
	    preIsHifun = !preIsHifun;
	    len++;
	    j++;
	  }

	ret = max(ret, len);
      }
    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
