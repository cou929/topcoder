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
class SoccerLeagues {
public:
  vector <int> points(vector <string> matches)
  {
    vector <int> ret;

    for (int i=0; i<matches.size(); i++)
      {
	int tmp = 0;
	for (int j=0; j<matches.size(); j++)
	  {
	    if (matches[i][j] == 'D')
	      tmp += 1;
	    else if (matches[i][j] == 'W')
	      tmp += 3;

	    if (matches[j][i] == 'D')
	      tmp += 1;
	    else if (matches[j][i] == 'L')
	      tmp += 3;
	  }
	ret.push_back(tmp);
      }
    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
