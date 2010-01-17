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
class Sortness {
public:
  double getSortness(vector <int> a)
  {
    double ret = 0;
    for (int i=0; i<a.size(); i++)
      {
	int sortness = 0;
	for (int j=0; j<a.size(); j++)
	  {
	    if (j < i)
	      if (a[j] > a[i])
		sortness++;

	    if (j == i)
	      continue;

	    if (i < j)
	      if (a[i] > a[j])
		sortness++;
	  }
	ret += sortness;
      }

    return ret / (double)a.size();
  }
   

};


// Powered by FileEdit
// Powered by TZTester 1.01 [25-Feb-2003]
// Powered by CodeProcessor
