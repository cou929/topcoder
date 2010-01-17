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
class ArithmeticProgression {
public:
  int a0;
  vector <int> seq;

  int check(double n)
  {
    for (int i=0; i<seq.size(); i++)
      {
	double d = ((double)a0 + (double)(i+1) * n);
	if (d < 0)
	  d += -0.99999999999999;
	int c = (int)d;

	if (c != seq[i])
	  {
	    if (c < seq[i])
	      return -1;
	    else
	      return 1;
	  }
      }

    return 0;
  }

  double minCommonDifference(int _a0, vector <int> _seq)
  {
    a0 = _a0;
    seq = _seq;
    vector <int> diffs;
    if (seq.size() == 0)
      return 0;

    diffs.push_back(seq[0] - a0);

    for (int i=1; i<seq.size(); i++)
      diffs.push_back(seq[i] - seq[i-1]);

    int mini = 10E6;
    int maxi = -10E6;
    for (int i=0; i<diffs.size(); i++)
      if (diffs[i] < 0)
	return -1;
      else
	{
	  mini = min(mini, diffs[i]);
	  maxi = max(maxi, diffs[i]);
	}

    if (maxi - mini > 1)
      return -1;

    double left = mini;
    double right = maxi;
    double ret = 0;

    for (int i=0; i<10000; i++)
      {
	double mid = (right + left) / (double)2;
	ret = mid;

	//	cout << left << " " << right << " " << mid << endl;

	if (left == right)
	  break;

	if (check(mid) < 0)
	  left = mid;
	else
	  right = mid;
      }

    printf("%20f\n", ret);
    if (check(ret) != 0)
      return -1;
    return ret;
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
