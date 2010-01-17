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
class SnowyWinter {
public:
  int snowyHighwayLength(vector <int> startPoints, vector <int> endPoints)
  {
    int ret = 0;
    int flg[startPoints.size()];
    memset(flg, 0, sizeof(flg));
    vector <pair <int, int> > sorted;

    for (int i=0; i<startPoints.size(); i++)
      sorted.push_back(make_pair(startPoints[i], endPoints[i]));

    sort(sorted.begin(), sorted.end());

    for (int i=0; i<sorted.size(); i++)
      {
	if (flg[i] == 0)
	  {
	    flg[i] = 1;
	    int under = sorted[i].first;
	    int upper = sorted[i].second;
	    for (int j=i+1; j<sorted.size(); j++)
	      if (flg[j] == 0 && sorted[j].first <= upper)
		{
		  flg[j] = 1;
		  upper = max(upper, sorted[j].second);
		}

	    ret += upper - under;
	  }
      }

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
