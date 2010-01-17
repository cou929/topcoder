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
class TournamentJudging {
public:
  int getPoints(vector <int> rawScores, vector <int> conversionFactor)
  {
    int ret = 0;

    for (int i=0; i<rawScores.size(); i++)
      {
	double d = (double)rawScores[i]/conversionFactor[i];
	ret += (int)(d+0.5);
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
