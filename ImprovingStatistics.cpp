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

class ImprovingStatistics {
public:
  int howManyGames(int played, int won)
  {
    int ini = ((double)won / (double)played) * 100;
    int ret = 1;

    if (ini == 100)
      return -1;

    while (1)
      {
	played++;
	won++;
	int tmp = ((double)won / (double)played) * 100;

	if (tmp - ini >= 1)
	  break;
	ret++;
      }

    return ret;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
