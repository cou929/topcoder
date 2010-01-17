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
class TheTournamentDivTwo {
public:
  int find(vector <int> points)
  {
    int ret = 0;
    int zeros = 0;

    for (int i=0; i<points.size(); i++)
      {
        ret += points[i]/2;
        zeros += points[i]%2;
      }

    if (zeros%2 == 1)
      return -1;
    else
      return ret + zeros/2;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
