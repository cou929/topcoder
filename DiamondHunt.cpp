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

using namespace std;

class DiamondHunt {
public:
  int countDiamonds(string mine)
  {
    int ret = 0;
    size_t pos;

    while (1)
      {
	pos = mine.find("<>");
	if (pos == string::npos)
	  break;
	mine.erase(pos, 2);
	ret++;
      }
    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
