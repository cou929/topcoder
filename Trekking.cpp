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

class Trekking {
public:
  int findCamps(string trail, vector <string> plans)
  {
    int mini = 100;

    for (int i=0; i<plans.size(); i++)
      {
	bool ok = true;
	int c = 0;
	for (int j=0; j<trail.size(); j++)
	  {
	    if (plans[i][j] == 'C')
	      {
		c++;
		if (trail[j] == '^') 
		  {
		    ok = false;
		    break;
		  }
	      }
	  }
	if (ok)
	  mini = min(mini, c);
      }

    if (mini == 100)
      mini = -1;

    return mini;
  }

   

};



// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
