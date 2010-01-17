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
class EquilibriumPoints {
public:
  vector <int> x;
  vector <int> m;

  double calc(double d)
  {
    double ret = 0;

    for (int i=0; i<x.size(); i++)
      {
	if (x[i] < d)
	  ret -= m[i] / (d - x[i]) / (d - x[i]);
	else
	  ret += m[i] / (x[i] - d) / (x[i] - d);
      }

    return ret;
  }

  double bs(int left, int right)
  {
    double d = 0, l = left, r = right;
    int i = 0;

    while (i++ < 500)
      {
	d = (l + r) / 2.0;
	double res = calc(d);

	if (res == 0)
	  break;
	else if (res < 0)
	  l = d;
	else if (0 < res)
	  r = d;
      }

    return d;
  }

  vector <double> getPoints(vector <int> _x, vector <int> _m)
  {
    x = _x;
    m = _m;
    vector <double> ret;

    for (int i=0; i<x.size()-1; i++)
      ret.push_back(bs(x[i], x[i+1]));

    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
